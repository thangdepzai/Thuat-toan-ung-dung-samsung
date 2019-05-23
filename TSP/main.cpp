#include<iostream>
#include<vector>
#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#define INF 400000000
#define N 20
using namespace std;
int mem[N][1<<N];
vector<pair<int, int> > c[N];
vector<int> ba(N, INF);


int tsp(int i, int S, int n){
    if(  S==(   (1<<n)-1  )   ){
        return ba[i];
    }
    if(mem[i][S]!=-1){
        return mem[i][S];
    }
    int res = INF;

    for(int j=0;j<c[i].size();j++){
        int k = c[i][j].first;
        int w = c[i][j].second;
        if(S&(1<<k)) continue;
        res = min(res, w + tsp(k, S|(1<<k), n));
    }
    mem[i][S]= res;
    return res;
}

int main(){
    memset(mem, -1, sizeof(mem));

    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        a--;
        b--;
        c[a].push_back(make_pair(b, w));
        if(b==0) ba[a] = w;

    }
    printf("%d\n", tsp(0, 1<<0, n));
    return 0;
}
