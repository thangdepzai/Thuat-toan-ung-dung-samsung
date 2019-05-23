#include<iostream>
#include<vector>
using namespace std;
int I = 0;
int C = 1;
int T = 2;
int H = 3;
int U = 4;
int S = 5;
int K = 6;
int A[7];
bool visited[10]={false};
int cnt =0;
int N;
void Solution(){
    cout<<A[I]*100+ A[C]*10 +A[T]<<"-"<< (A[K]*100 + 62)<<" +"<< A[H]*1000 + A[U]*100 +A[S]*10+A[T]<<endl;
    cnt++;
}
void Try(int k){
    for(int i=1; i<=9;i++){
        if(!visited[i]){
            A[k] = i;
            visited[i]= true;
            if(k==6){
                if(A[I]*100+ A[C]*10 +A[T]- (A[K]*100 + 62) + A[H]*1000 + A[U]*100 +A[S]*10+A[T]==N) Solution();
            }else{
                Try(k+1);
            }
            visited[i] = false;

        }
    }
}

int main(){
    cin>>N;
    Try(0);
    cout<<cnt<<endl;
    return 0;

}
