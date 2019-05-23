#include<iostream>
#include<vector>
using namespace std;
int n;
int m;
vector<int> A(10000);
vector<int> sum(10000,0);
int T=0;
bool check(int v, int k){
    return true;
}
int cnt =0;
void Solution(){
    cnt++;
}
int Try(int k){
    int T1 = sum[n-1]- sum[k];
    int max_v = (m-T-T1)/A[k];
    for(int v= 1; v<= max_v; v++){
        if(check(v,k)){
            T+=v*A[k];
            if(k==n-1)  {
                if(T==m) Solution();
            }else Try(k+1);
            T -= v*A[k];

        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>A[i];
        sum[i] = (i==0)?A[i]:(sum[i-1]+A[i]);
    }
    Try(0);
    cout<<cnt<<endl;

}
