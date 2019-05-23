#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#define N 1000
#define INF 10000000
#include<stack>
using namespace std;
int T;


int main(){
    cin>>T;
    cin.ignore();
    for(int j=0;j<T;j++){
       string  s ;
       getline(cin,s);
       int  n = s.size();
       stack<char> Q;
        bool check1 = true;
       for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{' ){
                Q.push(s[i]);

            }else{

                char _c ;
                if(s[i]==')') _c = '(';
                else if(s[i]==']') _c = '[';
                else _c = '{';
                bool check = false;
                if(Q.size()>0){
                    char t = Q.top();
                    Q.pop();
                    if(t==_c){
                        check = true;
                    }
                }
                if(check == false){
                    cout<<"0"<<endl;
                    check1 = false;
                    break ;
                }

            }
       }
       if(check1 == true){
            cout<<"1"<<endl;

       }
    }
    return 0;




}
