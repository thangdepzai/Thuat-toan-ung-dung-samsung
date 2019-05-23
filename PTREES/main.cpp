#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    vector<int> A(n);
    for(int i=0;i<n;i++) scanf("%d", &A[i]);
    sort(A.begin(), A.end());


    int ans=0;
    for(int i=n-1; i>=0; i--){
        int j = n-i;
        ans = max(j+A[i], ans);
    }
    printf("%d\n", ans+1);
    return 0;
}
