#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#define N1 10000
#define INF 10000000
#include<stack>
using namespace std;
int N,I,K;
int x[N1];
int sl =0;
int dem  =0;
bool stop = false;
void Solution(){
    dem++;
    if(dem==K){
        for(int i=0;i<N;i++) printf("%d ",x[i]);
        printf("\n");
        stop=  true;
    }
}
void Try(int k){
    if(stop) return;
    for(int i=0;i<=1;i++){
        if(stop) return;
        if( i==0 && sl>=I-1) continue;
        x[k] =i;
        int temp = sl;
        if(i==0) sl++;
        else sl =0;
        if(k==N-1){
            Solution();
            if(stop) return;
        }
        else Try(k+1);
        sl = temp;

    }
}

int main(){
    scanf("%d %d %d",&N,&K,&I);

    Try(0);
    if(stop==false) printf("-1\n");;
    return 0;

}
