#include <iostream>

int main(){
    int N = 5; 
    int A[N] = {5, 4,3,2,1}; //may be an error cazed by non constant value for an array 
    bool is_sorted = false;

    while(not is_sorted){
        int i = 0;
        is_sorted = true; //flag

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
    //O(n2)
    for(int i = 0; i<N; i++){
        std::cout<< A[i]<< '\t';
    }
}
