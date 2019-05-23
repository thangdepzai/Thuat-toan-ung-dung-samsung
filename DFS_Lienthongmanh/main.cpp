#include<iostream>
#include<vector>

using namespace std;


#define N 1000


int d[N];
int f[N];

vector<bool> visited(N, false);
vector<int> A[N];
vector<int> B[N];
vector<int> fin;
int t=1;
int n,m;
//12 22
//1 2
//1 4
//2 3
//2 5
//2 6
//3 7
//4 5
//4 6
//4 8
//5 1
//6 3
//6 8
//7 6
//7 9
//7 11
//8 9
//8 10
//9 11
//10 9
//10 12
//11 10
//12 11

void dfs(int s, bool G){
    if(G){
        visited[s]=true;
        d[s] =t;
        for( int u : A[s]){
            if(!visited[u]){
                t++;
                dfs(u, true);
        }
        }
        t++;
        f[s] = t;
        fin.push_back(s);
    }else{
        visited[s]=false;
        for( int u : B[s]){
            if(visited[u]){
                dfs(u, false);
            }
        }
        cout<<s+1<<endl;

    }

}

void DFS_G(){
    for( int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, true);
        }
    }
}

void find_strong_connected(){
    int i = n-1;
    while(i!=-1){
        if(visited[ fin[i] ]){
            dfs(fin[i], false);
            cout<<"------"<<endl;
        }
        i--;
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
            B[b].push_back(a);
    }
    DFS_G();

    find_strong_connected();
    return 0;
}


