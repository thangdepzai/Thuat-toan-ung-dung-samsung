#include<iostream>
#include<vector>
using namespace std;

vector<int> A(1000);
int n1;

void Swap( int i, int j ){
    int temp = A[i];
    A[i]= A[j];
    A[j] = temp;
}
int Patition( int L, int R){
    int pivot  = A[(L+R)/2];
    int index = L;
    int mid = (L+R)/2;
    Swap( R, mid);
    for(int i=L;i<=R;i++ ){
        if(A[i]<pivot){
            Swap( i, index);
            index++;
        }
    }
    Swap(R, index);
    return index;
}

void QuickSort( int L, int R){


    int index = Patition( L, R);
    if(index> L){
        QuickSort( L, index-1);
    }
    if(index <R){
        QuickSort( index +1, R);
    }
}


void Heapify(int i, int n){
    int L= 2*i;
    int R = 2*i+1;
    int _max = i;
    if(L<=n && A[L]> A[i]){
        _max = L;
    }
    if(R<=n && A[R]>A[_max]){
        _max = R;
    }
    if(_max !=i){
        Swap(_max, i);
        Heapify(_max, n);
    }

}
void BildHeap(int n){
    for(int i=n/2; i>=1; i--){
        Heapify(i,n);
    }
}
void HeapSort(int n){
    BildHeap(n);
    for(int i=n; i>=1; i--){
        Swap(1,i);
        Heapify(1, i-1);
    }
}
int main(){
    cin>>n1;
    for(int i=1;i<=n1;i++) cin>>A[i];
    //QuickSort( 0, n-1);
   HeapSort(n1);
    for(int i=1;i<=n1;i++) cout<<A[i]<<endl;

}
