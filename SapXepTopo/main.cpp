#include<iostream>
#include<vector>
#define N 1000
using namespace std;
int n, m;
vector<int> A[N];
int d[N]; // ban bac vao cua 1 dinh
vector<bool> isSorted(N, false);
//10 18
//1 6
//1 2
//2 3
//2 4
//2 7
//2 10
//3 10
//4 10
//4 9
//5 6
//5 1
//6 7
//6 2
//7 3
//8 2
//8 9
//8 4
//10 9

void sort_topo(int s){
    cout<<s+1<<endl;
    isSorted[s] = true;
    for(int u: A[s]){
        d[u]--;
        if(d[u]==0 && !isSorted[u]){
            sort_topo(u);
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        A[a].push_back(b);
        d[b]++;
    }
    for(int i =0;i<n;i++){
        if(d[i]==0 && !isSorted[i]){
            sort_topo(i);
        }
    }
    return 0;
}
