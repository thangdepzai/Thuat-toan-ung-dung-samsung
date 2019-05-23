#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 1000001
using namespace std;

int n, L1, L2;
int S[N]; // tong max ket thuc tai i
int A[N];

int dp(int k){
    if(k<L1) return A[k];
    if(S[k]!=-1) return S[k];

    int MAX = A[k];
    for( int i=(k>=L2)?k-L2:0; i<=k-L1;i++){
        MAX = max(dp(i)+ A[k],MAX);
    }
    S[k]= MAX;
    return S[k];

}

int main(){
        scanf("%d %d %d", &n, &L1, &L2);
        memset(S,-1, N*sizeof(int));
        for(int i=0;i<n;i++){
            scanf("%d", &A[i]);
        }
        for(int i=0;i<n;i++) dp(i);
        int MAX =-1;

        for(int i=0;i<n;i++){
                printf("\n%d ", S[i]);
            //MAX = max(MAX, S[i]);
        }
       // printf("%d\n", MAX);

    return 0;
}
