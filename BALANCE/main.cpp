#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;
int oper[]= {0, 1};
 int N, S;
vector<int> A(21);
int sum=0;
int ans =0;
int _min = 100000000;
void Try(int k){
    for(int i=0;i<2;i++){
        sum+= i*A[k];
        if(sum==S){
            ans++;
        }
        else if(k<N-1 && sum <  S) Try(k+1);
        sum -=i*A[k];
    }

}


int main(){
        scanf("%d %d", &N, &S);
        for( int i=0;i<N;i++){
            scanf("%d", &A[i]);
        }
        sum = 0;
        Try(0);
        printf("%d\n", ans);
       return 0;

}
