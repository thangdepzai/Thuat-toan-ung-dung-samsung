#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define N 1001
using namespace std;
int T;
int a, b,c;

struct State{
    int x;
    int y;
    int level;
    State(int _x, int _y, int _level){
        x= _x;
        y=_y;
        level = _level;
    }
};
bool visited[N][N];
// 6 trang thai
//1. emty s1
//2. emty s2
// 3. do s2 vao s1
//4 do s1 vao s2
//5. do day s1
//6 do day s2


void BFS( ){
    queue<State> Q;

    Q.push(State(0,0,0));
    visited[0][0]= true;
    if(c==0){
        cout<<"0"<<endl;
        return ;
    }

    while(Q.size()>0){
        State p = Q.front();
        Q.pop();
        //1. emty s1
        if(!visited[0][p.y]){
            Q.push( State(0,p.y, p.level+1));
            visited[0][p.y] = true;
            if(p.y==c){
                cout<<p.level+1<<endl;
                return;
            }
        }
        //2. emty s2
        if(!visited[p.x][0]){
            Q.push( State(p.x,0,p.level+1));
            visited[p.x][0] = true;
            if(p.x==c){
                cout<<p.level+1<<endl;
                return;
            }
        }
        //3. do day s1
        if(!visited[a][p.y]){
            Q.push( State(a,p.y,p.level+1));
            visited[a][p.y] = true;
             if(p.y==c|| a==c){
                cout<<p.level+1<<endl;
                return;
            }
        }
        //4 do day s2
        if(!visited[p.x][b]){
            Q.push( State(p.x,b,p.level+1));
            visited[p.x][b] = true;
            if(p.x==c|| b==c){
                cout<<p.level+1<<endl;
                return;
            }
        }
        // 5. do s2 vao s1
        if(p.x+p.y>=a ){
            if(!visited[a][p.y-(a-p.x)]){
                Q.push( State(a,p.y-(a-p.x),p.level+1));
                visited[a][p.y-(a-p.x)] = true;
                if(a==c|| p.y-(a-p.x)==c){
                    cout<<p.level+1<<endl;
                    return;
                }

            }
        } else if(!visited[p.x+p.y][0]) {
            Q.push(State(p.x+p.y,0,p.level+1));
            visited[p.x+p.y][0] = true;
            if(p.x+p.y==c){
                cout<<p.level+1<<endl;
                return;
            }

        }
        //6 do s1 vao s2
        if(p.x+p.y>= b ){
            if(!visited[p.x+p.y -b][b]){
                Q.push( State(p.x+p.y -b,b,p.level+1));
                visited[p.x+p.y -b][b] = true;
                 if(p.x+p.y -b==c || b==c){
                    cout<<p.level+1<<endl;
                    return;
                }

            }
        } else  if(!visited[0][p.x+p.y]){
            Q.push( State(0, p.x+p.y,p.level+1));
            visited[0][p.x+p.y] = true;
             if(p.x+p.y==c){
                cout<<p.level+1<<endl;
                return;
            }

        }


    }
     cout<<"-1"<<endl;

}
int main(){
    cin>>T;
    for(int t=0;t<T; t++){
        memset(visited, 0, sizeof(visited));
        cin>>a>>b>>c;
        BFS();
    }

}
