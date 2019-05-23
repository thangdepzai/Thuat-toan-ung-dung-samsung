#include<iostream>
#include<vector>
using namespace std;
int sum=0;
int A[1000];
int N;
int S;
int cnt =0;
void Solution(){
    cnt++;
}
void Try(int k){
    for(int i=0;i<=1;i++){
        if(i*A[k]+sum<= S){
            sum+= i*A[k];
            if(sum==S) Solution();

            else if(k<N-1) Try(k+1);
            sum-= i*A[k];
        }
    }
}

int main(){
    cin>>N>>S;
    for(int i=0;i<N; i++){
        cin>>A[i];
    }
    Try(0);
    cout<<cnt<<endl;

}
