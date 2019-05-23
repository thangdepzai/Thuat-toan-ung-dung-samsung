#include<stdio.h>
#include<algorithm>
#include<vector>
#define N 1000001
using namespace std;



int n;



int main(){
    scanf("%d", &n);
    vector<float> A(n);
    for(int i=0;i<n;i++) scanf("%f", &A[i]);
    sort(A.begin(), A.end());
    for(int i=0;i<n;i++) printf("%0.2f ", A[i]);


}




