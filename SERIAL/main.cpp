#include<iostream>
#include<vector>
using namespace std;
int sum=0;
int A[1000]={0};
int N;

void Solution(int k){
    for(int i=0;i<=k;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void Try(int k){
    for(int i=(k==0)?1:A[k-1];i<=(N-sum);i++){

        A[k] =i;
        sum+= i;
        if(sum==N) Solution(k);
        else if(sum<N) Try(k+1);
        sum -= i;
    }
}
int main(){
    cin>>N;
    Try(0);
    //cout<<cnt<<endl;
    return 0;

}


