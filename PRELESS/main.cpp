#include<iostream>
#include<vector>
#define N 10001
using namespace std;

//10
//3 3 6 5 10 7 8 9 1 1


int n;
vector<int> A(N);
int c[N];
int cnt =0;


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n; j++){
            if(A[j]>A[i]) c[j]++;
        }
    }
    int _m = -1;
    for(int i=0;i<n; i++) _m = max(_m, c[i]);
    cout<<_m<<endl;

}
