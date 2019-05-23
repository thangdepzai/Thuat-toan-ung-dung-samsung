#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#define N 100002
#define M 1000000007
using namespace std;
int n;

vector<int> A(N);
vector<int> B(N);
stack<int> Q;
stack<int> Dau;
int oper[] ={-1,1};
int uutien(int x){
    return (x<2)?0:1;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    for(int i=0;i<n-1;i++){
        scanf("%d", &B[i]);
    }
    Q.push(A[0]);

    Dau.push(B[0]);
    for(int i=1; i<n-1;i++){
        Q.push(A[i]);
        if(uutien(B[i])<= uutien(Dau.top()) ){
                while(Dau.size()>0 && uutien(B[i])<= uutien(Dau.top()) ){
                    int p = Dau.top();
                    int k1 = Q.top();
                    Q.pop();
                    int k2 = Q.top();
                    Q.pop();
                    if(p!=2){
                        Q.push(k2 + oper[p]*k1);
                    }else Q.push(k2*k1);
                    Dau.pop();
                }
        }
        Dau.push(B[i]);

    }
    Q.push(A[n-1]);
    while(Dau.size()){
        int p = Dau.top();
        int k1 = Q.top();
        Q.pop();
        int k2 = Q.top();
        Q.pop();
        int ans =0;
        if(p==2) ans =  k1 *k2;
        else ans = k2 + oper[p]*k1;
        Q.push(ans);
        Dau.pop();
    }
    //cout<<Q.size()<<endl;
    cout<<Q.top()<<endl;
    return 0;


}
