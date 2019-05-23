#include<iostream>
#include<vector>
using namespace std;
int n;
vector<bool> isVisited(10001, false);
vector<int> A(10001);
int dem =0;
bool check =true;
int M;
void Solution(){
    dem++;
    if(dem==M){
        for(int i=0;i<n;i++) cout<<A[i]<<" ";
        check = false;
    }
}


void Try(int k){
    if(!check) return;
    for(int i=1;i<=n;i++){
        if(!isVisited[i-1]){
            isVisited[i-1] =1;
            A[k] = i;
            if(k==n-1) Solution();
            else Try(k+1);
            isVisited[i-1] =0;
        }
    }
}
int main(){
    cin>>n>>M;
    Try(0);
    if(check) cout<<"-1"<<endl;
    return 0;
}
