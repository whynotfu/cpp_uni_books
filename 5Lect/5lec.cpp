#include <iostream>
using namespace std;

const int MAX_A_SIZE = 100;

int main(){
    int N=10000;
    int A[N];
    for(int i=0; i<N;i++){
        A[i] = N-i;
    }
    int i =0;
    while (i< N-1){
        if(A[i]>A[i+1]){
            int B = A[i];
            A[i]=A[i+1];
            A[i+1]= B;git 
            i=0;
        }else{
        i++;
        }
    }
    cout<< "\n";
}

void bubble_sort(){ 
    int N=500;
    int A[N] = {1,3,2,8,6,5};
    int i =0;
    while (i< N-1){
        if(A[i]>A[i+1]){
            int B = A[i];
            A[i]=A[i+1];
            A[i+1]= B;
            i=0;
        }else{
        i++;
        }
    }
    for(int j =0; j<N;j++){
        cout<< A[j]<<"\t";
    }
    
}
void if_sorted(){
        int N = 5;
    int A[N] ={1,7,4,5};

    bool is_sorted=true;
    int i =0;
    while(i<N-1){
        if(A[i]>= A[i+1]){
            is_sorted=false;
            break;
        }
        i++;
    }
    cout<< is_sorted;
}

void stack(){
    int N = MAX_A_SIZE;
    int A[N]; // doesn't work with old compilators; 
    int top=0;
    int x; 
    cin>>x;
    while(x!=0){
        A[top] = x;
        top++;
        cin>> x;
    }
    while(top>0){
        cout<< A[--top]<< '\t';
    }
    cout<< '\n';
}

void unlimit_arr(){
    int N = MAX_A_SIZE;
    int A[N]; // doesn't work with old compilators; 
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



// That was before
void V1(){
    //---v1
    // B =A           l-value error 
    //---v2
    int N = 5;
    int A[N] = {1,2,3,4,5}; // doesn't work with old compilators; 
    int B[N];

    for(int i = 0; i<N; i++){
        B[i]=A[N - i-1];
    }

    /*B array and A will have the same values*/
}
    
    
void V3_revers(){
    int N = 5;
    int A[N] = {1,2,3,4,5}; // doesn't work with old compilators; 
    int B[N];
    for(int i = 0; i<N; i++){
        B[i]=A[N - i-1];
    }

}

void V4_reverseW3var(){
    int N = 5;
    int A[N] = {1,2,3,4,5};
     for(int i=0; i<N/2; i++){ // N/2 so we won't do the algoritm 2 times across the array
        int tmp = A[N-i-1];
        A[N-i-1] = A[i];
        A[i] = tmp;
    }
    for(int i=0; i<N; i++){
        cout<< A[i]<<"\t";
    }
}

