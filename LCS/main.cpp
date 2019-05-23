#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 1000
using namespace std;
int d[N][N];

int A[]= {3,7,2,5,1,4,9};
int B[] ={4,3,2,3,6,1,5,4,9,7};
int lcs(int i, int j){
    if(i==-1|| j==-1) return 0;

    if(d[i][j]!=-1) return d[i][j];

    if(A[i]==B[j]) d[i][j] = lcs(i-1, j-1) +1;
    else d[i][j] = max(lcs(i, j-1), lcs(i-1, j));
    return d[i][j];

}


int main(){
    memset(d, -1, N*N*sizeof(int));
    printf("%d\n", lcs(6,9));
    for(int i=0; i<7; i++){
         for(int j=0; j<10; j++) printf("%d ", d[i][j]);
         printf("\n");
    }




}

