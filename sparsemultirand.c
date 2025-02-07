#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define NZ 20
void toSparse(int mat[N][N],int sp[][3],int *cnt){
int k=0;
for(int i=0;i<N;i++){
for(int j=0;j<N;j++){
if(mat[i][j]!=0){
sp[k][0]=i;
sp[k][1]=j;
sp[k][2]=mat[i][j];
k++;
}
}
}
*cnt=k;
}
void mulSparse(int A[][3],int ac,int B[][3],int bc,int C[][3],int *cc){
int res[N][N]={0};
for(int i=0;i<ac;i++){
for(int j=0;j<bc;j++){
if(A[i][1]==B[j][0]){
res[A[i][0]][B[j][1]]+=A[i][2]*B[j][2];
}
}
}
int k=0;
for(int i=0;i<N;i++){
for(int j=0;j<N;j++){
if(res[i][j]!=0){
C[k][0]=i;
C[k][1]=j;
C[k][2]=res[i][j];
k++;
}
}
}
*cc=k;
}
void printSparse(int sp[][3],int cnt){
printf("Row\tCol\tValue\n");
for(int i=0;i<cnt;i++){
printf("%d\t%d\t%d\n",sp[i][0],sp[i][1],sp[i][2]);
}
}
int main(){
int A[N][N]={0},B[N][N]={0};
int spA[NZ][3],spB[NZ][3],spC[NZ][3];
int cntA,cntB,cntC;
srand(time(0));
for(int i=0;i<NZ;i++){
int r,c,v;
do{
r=rand()%N;
c=rand()%N;
}while(A[r][c]!=0);
v=(rand()%100)+1;
A[r][c]=v;
}
for(int i=0;i<NZ;i++){
int r,c,v;
do{
r=rand()%N;
c=rand()%N;
}while(B[r][c]!=0);
v=(rand()%100)+1;
B[r][c]=v;
}
printf("Sparse Matrix A:\n");
toSparse(A,spA,&cntA);
printSparse(spA,cntA);
printf("Sparse Matrix B:\n");
toSparse(B,spB,&cntB);
printSparse(spB,cntB);
mulSparse(spA,cntA,spB,cntB,spC,&cntC);
printf("Resultant Sparse Matrix:\n");
printSparse(spC,cntC);
return 0;
}
