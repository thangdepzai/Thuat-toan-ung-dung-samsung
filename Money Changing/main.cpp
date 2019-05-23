#include<iostream>

using namespace std;


int A[]={500, 100, 50, 10, 5,1};
int n;
int N=1000;
int c =0;
void Try(int k){
    for(int i=0;i<6; i++){
        if(A[i]<= k){
            int m = k/A[i];
            k = k%A[i];
            c+=m;
            Try(k);
            break;
        }
    }
}



int main(){
    cin>>n;
    n = N-n;

    Try(n);
    cout<<c<<endl;

}
