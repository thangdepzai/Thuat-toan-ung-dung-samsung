#include<iostream>
#include<vector>
using namespace std;
int n;
int m;
int T=0;
vector<int> A(1000, 0);
void Solution(){
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
}
void Try(int k){
    for(int v=0;v<=1;v++){
        if(v==0 || T< m){
            if(v==1) T++;
            A[k-1] = v;
           if(k==n){
                if(T==m) Solution();
           }
            else Try(k+1);
            if(v==1){
                T--;
                A[k-1] -= 1;
            }

        }

    }

}

int main(){

    cin>>n>>m;

    Try(1);
    return 0;

}
