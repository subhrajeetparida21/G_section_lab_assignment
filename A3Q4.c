#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to generate an array
void generate_array(int arr[], int n, int type) {
    if (type == 0) {
        for (int i = 0; i < n; i++) arr[i] = i + 1;
    } else if (type == 1) {
        for (int i = 0; i < n; i++) arr[i] = n - i;
    } else {
        for (int i = 0; i < n; i++) arr[i] = rand() % (n * 10);
    }
}

// Function to measure execution time
double measure_time(void (*sort_func)(int[], int), int arr[], int n) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sort_func(arr, n);
    gettimeofday(&end, NULL);
    return ((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec)) / 1000000.0;
}

// Function to write CSV file
void write_csv(const char *filename, int sizes[], int count, void (*sort_func)(int[], int)) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "Size,Best, Worst, Average\n");
    
    for (int i = 0; i < count; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed for size %d\n", n);
            continue;
        }
        
        generate_array(arr, n, 0);
        double best = measure_time(sort_func, arr, n);
        
        generate_array(arr, n, 1);
        double worst = measure_time(sort_func, arr, n);
        
        generate_array(arr, n, 2);
        double avg = measure_time(sort_func, arr, n);
        
        fprintf(file, "%d,%.6f,%.6f,%.6f\n", n, best, worst, avg);
        free(arr);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <array_size1> <array_size2> ...\n", argv[0]);
        return 1;
    }

    srand(time(NULL));
    int sizes[argc - 1];
    int count = 0;
    
    for (int i = 1; i < argc; i++) {
        int n = atoi(argv[i]);
        if (n <= 0) {
            printf("Please enter a valid array size for argument %d.\n", i);
            continue;
        }
        sizes[count++] = n;
    }
    
    write_csv("bubble_sort.csv", sizes, count, bubble_sort);
    write_csv("selection_sort.csv", sizes, count, selection_sort);
    write_csv("insertion_sort.csv", sizes, count, insertion_sort);
    
    printf("CSV files generated successfully.\n");
    return 0;
}
