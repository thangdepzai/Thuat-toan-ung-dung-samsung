#include<iostream>
#include<vector>


using namespace std;
int oper[]= {-1, 1};

int sum=0;
int ans =0;
void Try(int k,int N,int S){
    if(ans>0) return;
    for(int i=0;i<2;i++){
        if(ans>0) return;
        sum+= oper[i]*k;
        if(k==N && sum==S){
            ans++;
            return ;
        }
        else if(k<N) Try(k+1, N, S);
        sum -=oper[i]*k;
    }

}


int main(){
    int T;
    cin>>T;
    for(int i=0;i<T; i++){
        int N, S;
        cin>>N>>S;
        sum=0;
        ans =0;
        Try(1, N, S);
        cout<<ans<<endl;

    }
}
