#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define N 1000001
using namespace std;
int n;
int dem =0;
struct time {
    int s;
    int f;
};
vector<time> A;
int D[N];
bool sosanh( time time1, time time2){
    return time1.f< time2.f;
}
int FindLastestConflict(int k){
    for (int j=k-1; j>=0; j--)
    {
        if (A[j].f <= A[k].s)
            return j;
    }
    return -1;
}
int DP( int k){

    if(k==0) return A[0].f - A[0].s ;
    if(D[k]!=-1) return D[k];
    // find phan tu co time f lon nhst ms conflict voi phan tu thu k
    int i = FindLastestConflict(k);
    int value = A[k].f - A[k].s;
    dem++;

    if( i!=-1) value += DP(i);
    // neu bo luon phan tu thu k
    int value2 = DP(k-1);
    if(value < value2){
        dem--;
        value= value2;
    }
    D[k]= value;
    return D[k];
}
int main(){
    scanf("%d", &n);
    memset(D,-1, (n+1)*sizeof(int));
    for(int i=0;i<n; i++){
        time t;
        scanf("%d %d", &t.s, &t.f);
        A.push_back(t);
    }
    sort(A.begin(), A.end(), sosanh);
    int val = DP(n-1);
    printf("%d\n", val);
    return 0;



}
