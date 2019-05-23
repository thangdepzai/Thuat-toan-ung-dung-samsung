#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 20
#define N 30
using namespace std;

int n, m;


bool check[N][N];

bool Matrix[M+1][N];
bool KetQua[M+1][N];

int MAX[M+1];
bool isDone = false;
int MAX_LOAD =N;

bool isOk(int t , int k){
    if(!Matrix[t][k]) return false; // neu giao vien khong day mon k

    for(int i=0;i<n; i++){
        if(KetQua[t][i] && check[i][k]) return false;// neu giao vien da day 1 mon i khong duoc trung voi mo k
    }
    return true;
}
void Solution(){
    isDone = true;
    int max_load =0;
    for(int i=1; i<=m;i++) max_load = max(max_load, MAX[i]);
    MAX_LOAD = min(MAX_LOAD, max_load);
}
void Try(int k){
    for(int i=1;i<=m; i++){
        if(isOk(i, k) ){
            KetQua[i][k] = true;
            MAX[i]++;
            if(k==n-1) Solution();
            else if(k<n-1) Try(k+1);
            KetQua[i][k] = false;
            MAX[i]--;
        }
    }
}
int main(){
    scanf("%d %d", &m, &n);
    //cin>>m>>n;
    for(int i=1;i<=m; i++){
       int k;
       scanf("%d", &k);
     //  cin>>k;
       for(int j=0;j<k;j++){
           int a;
           scanf("%d", &a);
         //  cin>>a;
           a--;
          Matrix[i][a]=1;
       }


    }
    int k;
     scanf("%d", &k);
    //cin>>k;
    for(int i=0;i<k;i++){
        int a, b;
         scanf("%d %d", &a, &b);
       // cin>>a>>b;
        a--;
        b--;
        check[a][b]= true;
        check[b][a]= true;
    }
    Try(0);
    if(isDone){
        printf("%d\n", MAX_LOAD);
    }else printf("-1\n");
    return 0;



}
