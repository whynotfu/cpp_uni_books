#include <iostream>
using namespace std;

int main(){
    int N = 5; 
    int A[N] = {5, 4,3,2,1};
    bool is_sorted = false;

    while(not is_sorted){
        int i = 0;
        is_sorted = true;

        while(i< N-1){
        if(A[i]>A[i+1]){
            int tmp =A[i];
            A[i] = A[i+1];
            A[i+1] =tmp;
            is_sorted = false;
        }
        i+=1;
        }

    }
    for(int i = 0; i<N; i++){
        cout<< A[i]<< '\t';

    }


    
}