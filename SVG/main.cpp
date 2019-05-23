#include<iostream>
#include<vector>
#define N 1001
#include<algorithm>
using namespace std;

int n;
struct sv{
    int a;
    int b;
};
vector<sv> C(N);

bool gioihon(sv A, sv B){
    return (A.a>B.a && A.b>B.b);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
            int a, b;
            cin>>a>>b;
            C[i].a = a;
            C[i].b= b;
    }
    int dem =0;
    for(int i=0;i<n;i++){
        bool check = false;
        for(int j=0;j<n;j++){
            if(i!=j && gioihon(C[j], C[i])){
                check = true;
                break;

            }
        }
        if(!check) dem++;
    }
    cout<<dem<<endl;
    return 0;

}
