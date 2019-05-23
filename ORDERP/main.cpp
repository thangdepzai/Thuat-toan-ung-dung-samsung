#include<iostream>
#include<vector>
#define N 12
using namespace std;




int n, K;
vector<int> p[N];
vector<bool> isVisited(N, false);
int c[N];
int cnt =0;



void Try(int k){
    for(int v= 1; v<=n; v++){
        if((!isVisited[v])  && c[v]==0 ){
           // X[k] = v;
            isVisited[v] = true;
            for(int i =0;i<p[v].size();i++) { int b = p[v][i]; c[b]++;}
            if(k==n){
                cnt++;
            }else if(k<n)  Try(k+1);
            for(int i =0;i<p[v].size();i++) { int b = p[v][i]; c[b]--;}
            isVisited[v] = false;
        }
    }
}
int main(){

    cin>>n;
    cin>>K;
    for(int i=0;i<K; i++){
        int a, b;
        cin>>a>>b;
        p[b].push_back(a);
    }
    Try(1);
    cout<<cnt<<endl;
return 0;}
