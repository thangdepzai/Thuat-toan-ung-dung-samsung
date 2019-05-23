#include<iostream>
#include<vector>
using namespace std;
int n=9;
int m;
int A[9][9];
int cnt =0;
int dem =0;
int Row=-1, Col=-1;


//4 0 0 0 0 0 0 0 0
//0 8 0 0 0 0 0 4 0
//0 3 0 2 0 8 1 0 5
//3 0 0 9 1 0 2 0 0
//6 4 0 0 0 5 9 0 0
//7 0 0 3 8 0 4 0 0
//0 7 0 6 0 1 3 0 4
//0 1 0 0 0 0 0 2 0
//5 0 0 0 0 0 0 0 0
void Init(){
 for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        cin>>A[i][j];
        if( A[i][j]==0) cnt ++;
    }
 }
}
bool check(int x,int y, int val){
    for(int j =0 ; j<9 ; j++ ) if(A[x][j]==val) return false;
    for(int i =0 ; i<9 ; i++ ) if(A[i][y]==val) return false;

    int b_x = (x/3)*3;
    int b_y = (y/3)*3;
    for(int i = b_x; i<b_x+3; i++){
        for(int j= b_y; j<b_y+3; j++){
            if(A[i][j]==val) return false;
        }
    }
    return true;
}
void Solution(){
    for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        cout<<A[i][j]<<" ";
    }
    cout<<endl;
 }
 cout<<endl;
}

void GetNextCell(int x, int y){
    Row =-1;
    Col =-1;
    if(y<n-1) {
        for(int i=y; i<n; i++) {
            if(A[x][i]==0) {
                Row = x;
                Col = i;
                return;
            }
        }
        y=n-1;

    }
    if(y == n-1){
        if(x<n-1){
            x++;
            y=0;
            GetNextCell(x, y);
        }else if(x==n-1) return;
    }
}
 void Try(int x, int y){
     for(int val= 1; val<=9;val++){
            if(check(x,y, val)){
                A[x][y] = val;
                dem++;

                if(dem == cnt){
                        Solution();
                        return;

                }
                else{
                    GetNextCell(x,y);
                    if(Row !=-1 && Col !=-1) Try(Row, Col);
                }
                dem--;
                A[x][y]=0;
            }

     }
 }


int main(){
    Init();
    cout<<endl;
    GetNextCell(0,0);

    if(Row !=-1 && Col !=-1) Try(Row, Col);
}



