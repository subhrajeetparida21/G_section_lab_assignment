#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 20
#define NON_ZERO 20
void transpose_sparse(int sparse[][3],int non_zero){
int trans[non_zero][3];
for(int i=0;i<non_zero;i++){
trans[i][0]=sparse[i][1];
trans[i][1]=sparse[i][0];
trans[i][2]=sparse[i][2];
}
printf("\nTransposed Sparse Matrix:\n");
printf("Row\tCol\tValue\n");
printf("%d\t%d\t%d\n",SIZE,SIZE,non_zero);
for(int i=0;i<non_zero;i++){
printf("%d\t%d\t%d\n",trans[i][0],trans[i][1],trans[i][2]);
}
}
int main(){
int mat[SIZE][SIZE]={0};
int sparse[NON_ZERO][3];
int non_zero=0;
srand(time(0));
for(int i=0;i<NON_ZERO;i++){
int row,col,value;
do{
row=rand()%SIZE;
col=rand()%SIZE;
}while(mat[row][col]!=0);
value=(rand()%100)+1;
mat[row][col]=value;
}
printf("Generated Matrix:\n");
for(int i=0;i<SIZE;i++){
for(int j=0;j<SIZE;j++){
printf("%d ",mat[i][j]);
}
printf("\n");
}
int k=0;
for(int i=0;i<SIZE;i++){
for(int j=0;j<SIZE;j++){
if(mat[i][j]!=0){
sparse[k][0]=i;
sparse[k][1]=j;
sparse[k][2]=mat[i][j];
k++;
}
}
}
printf("\nSparse Representation:\n");
printf("Row\tCol\tValue\n");
printf("%d\t%d\t%d\n",SIZE,SIZE,NON_ZERO);
for(int i=0;i<NON_ZERO;i++){
printf("%d\t%d\t%d\n",sparse[i][0],sparse[i][1],sparse[i][2]);
}
transpose_sparse(sparse,NON_ZERO);
return 0;
}
