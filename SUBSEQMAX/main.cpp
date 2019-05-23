#include<iostream>
#include<vector>
#define N 1000000
using namespace std;
int sum=0;
int n;
vector<int> A(N);
vector<int> dp(N, -1);


int DP(int k){
    if(k==0) return A[k];

    if(dp[k]!=-1) return dp[k];
    if(k<n){
        dp[k] =  max(DP(k-1)+A[k], A[k]);
        return dp[k];
    }
}



int main(){

    cin>>n;
    for(int i =0;i<n;i++){
        int a;
        cin>>a;
        A.push_back(a);
    }
    int ans =0;
    for(int i=0;i<n;i++) ans = max(DP(i), ans);
    cout<<ans<<endl;
}

