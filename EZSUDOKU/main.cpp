#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int A[8][8];
int Row=-1, Col=-1;
int hang[8][9];
int cot[8][9];
int block[2][2][9];
int t= 0;
bool solved = false;

bool check(int x,int y, int val){
    if(hang[x][val]>0) return false;
    if(cot[y][val]>0) return false;
    if(block[x/4][y/4][val]>1) return false;
    return true;
}

void Solution(){
    solved = true;
    printf("Test case #%d: YES\n", t);
    for(int i=0;i<8;i++){
            for(int j =0; j<8; j++){
                printf("%d ", A[i][j]);
            }
            printf("\n");

    }
}


void GetNextCell(int x, int y){
    Row =-1;
    Col =-1;
    y++;
    if(y>=8){
        x++;
        y=y%8;
    }
    if(x>7) return;
    if(A[x][y]!=0) GetNextCell(x,y);
    else {
        Row =x;
        Col =y;
    }
}

void Try(int x, int y){
    for(int val= 1; val<=8;val++){
            if(solved) return;
            if(check(x,y, val)){
                A[x][y] = val;
                hang[x][val]++;
                cot[y][val]++;
                block[x/4][y/4][val]++;
                GetNextCell(x,y);
                if(Row==-1 && Col==-1) {
                    Solution();
                    return;
                }
                else Try(Row, Col);
                A[x][y]=0;
                hang[x][val]--;
                cot[y][val]--;
                block[x/4][y/4][val]--;
            }

    }
}



int main(){
    int T;
    cin>>T;
    for(t= 1; t<=T; t++){
        memset(hang, 0, sizeof(hang));
        memset(cot, 0, sizeof(cot));
        memset(block, 0, sizeof(block));
        bool err = false;
        solved = false;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                int a;
                cin>>a;
                 A[i][j]=a;
                if(a!=0){

                    hang[i][a]++;
                    cot[j][a]++;
                    block[i/4][j/4][a]++;
                    if(hang[i][a]>1 || cot[j][a]>1 || block[i/4][j/4][a]>2) err = true;
                }


            }

        }
        if(err){
            printf("Test case #%d: NO\n",t);
            continue;
        }

        GetNextCell(0,-1);
        if(Row ==-1 && Col==-1 ) Solution();
        else Try(Row, Col);
        if(!solved) printf("Test case #%d: NO\n",t);

    }
    return 0;
}
