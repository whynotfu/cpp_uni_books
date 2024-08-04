#include <iostream>
using namespace std;

const int MAX_A_SIZE = 100;

int main(){
    int N = MAX_A_SIZE;
    int A[N]; // На старых компиляторах незя так писать 
    int top=0;
    int x; 
    cin>>x;
    while(x!=0){
        A[top] = x;
        top++;
        cin>> x;
    }
    for(int i=0; i<top; ++i){
        cout<< A[i]<< '\t';

    }

}

    //---v1
    // B =A           l-value незя так
     //^ это адрес начала массива 


    //---v2
    /*
    for(int i = 0; i<N; i++){
        B[i]=A[N - i-1];
    }
*/
    // ----v3 реверс через 3ю переменную 





/*
int pop(){
        for(int i = 0; i<N; i++){
        B[i]=A[N - i-1];
    }
}
    for(int i=0; i<N/2; i++){
        int tmp = A[N-i-1];
        A[N-i-1] = A[i];
        A[i] = tmp;

    }
    for(int i=0; i<N; i++){
        cout<< A[i]<<"\t";

    }
*/
