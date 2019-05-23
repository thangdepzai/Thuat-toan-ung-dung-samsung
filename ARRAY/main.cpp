#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A(5);
vector<int> B(1000);
int n1,n2;



bool Binary_Search(int x, int L, int R){
    if(L>R) return false;
    if(L==R && A[L] !=x) return false;
    int mid = (L+R)/2;
    if(A[mid]==x){
        return true;
    }
    if(A[mid]<x) return Binary_Search( x, mid+1, R);
    else return Binary_Search( x, L, mid-1);

}


int main(){
    cin>>n1>>n2;
    A.resize(n1);
    for(int i=0;i<n1;i++) cin>>A[i];
    for(int i=0;i<n2;i++) cin>>B[i];
    sort(A.begin(), A.end());
    int c =0;
    for(int i=0;i<n2;i++){
        if(Binary_Search( B[i], 0, n1-1)) c++;
    }
    cout<<c<<endl;
    return 0;


}
