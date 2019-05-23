#include<iostream>
#include<vector>
using namespace std;
int oper[]= {-1, 1};
 int N, S;
vector<int> A(31);
int sum=0;
int ans =0;
void Try(int k){
    for(int i=0;i<2;i++){
        sum+= oper[i]*A[k];
        if(k==N-1 && sum==S){
            ans++;
        }
        else if(k<N-1) Try(k+1);
        sum -=oper[i]*A[k];
    }

}


int main(){

        cin>>N>>S;
        for( int i=0;i<N;i++){
            cin>>A[i];

        }
        sum = A[0];
        Try(1);
        cout<<ans<<endl;

}
