#include <iostream>
void start(void);

int sizeO(void);

int* readMassive(int*, int);
char* readCharM(char*, int);

void buble(int*, int);
void secondS(char*, int);
void thirdS(int*, int);

void mergeSort(int*, int, int );
void merge(int*, int, int, int );


int main(){
    start();

    return 0;
}

void start(void){
    std::cout<<"Welcome to the program!\nChoose the task\n\t1. Buble sort\n\t2. Counted sort\n\t3. Merg sort\n\t4. Exit\n";
    short n; 
    std::cin>>n;

    int size;
    if (n>=1 && n<=3){
        size = sizeO();
    }
    int m[size]; // могут быть проблемы в VS и со старыми коспиляторами ( у меня VS CODE g++ )
    int* p = m;

    char mas2[size];
    char* p2 = mas2;


    switch(n){
        case 1:
            buble(readMassive(p, size),  size);
            break;
        case 2:
            secondS(readCharM(p2, size), size);
            break;
        case 3:
            thirdS(readMassive(p, size), size);
            break;
        default:
            std::cout<<"Thank you :) ";  
            break;
    }

}

int sizeO(){
    std::cout<<"Enter size of your massive: ";
    int n; 
    std::cin>>n;
    return n;
}
/* READING MASSIVES*/
int* readMassive(int* m, int size){
    for(int i=0; i<size; i++){
         std::cin>>m[i];
    }
    
    int* mas = m;
    return mas;
}
char* readCharM(char* mas2, int size){
    for(int i=0; i<size; i++){
        std::cin>>mas2[i];
    }
    char* mas = mas2;
    return mas;
}


/* SORTING METHODS*/
void buble(int* masiv, int size ){

    bool is_sorted = false;
    while( is_sorted == false){
        int i =0;
        is_sorted = true; 

        // for(int j = 0; j<sizeO; j++){
        //     std::cout<< *(masiv+j)<< ' ';
        // }
         while(i < size-1){
            if(*(masiv+i)> *(masiv+i+1)){
                int tmp = *(masiv+i);
                *(masiv + i) = *(masiv + i +1);
                *(masiv + i +1) = tmp;
                is_sorted = false;
             }
             i++;
        }

    }
    for(int j = 0; j<size; j++){
        std::cout<< *(masiv + j)<< " ";
    }
    std::cout<<std::endl;
    start();
}

void secondS(char* masiv, int size){

    const int alphabet= 26;
    int count[alphabet] ={0};
    
    for(int i = 0; i< size; i++){
        int j = *(masiv+i)-'a';
        count[j]++;
    }
    int i = 0;
    int j=0;
    while(j<alphabet && i< size){
        if(count[j]>0){
            *(masiv+i) = 'a'+j;
            i++;
            count[j]--;
        }
        else{
            j++;
        }
    }

    for(int p =0; p<size; p++){
        std::cout<<*(masiv+p)<< " ";
    }

    std::cout<<std::endl;

    start();
}
void thirdS(int* masiv, int size){
    mergeSort(masiv, 0, size - 1);
    
    for(int i =0; i<size; i++){
        std::cout<<*(masiv +i) << " ";
    }

    std::cout<<std::endl;
    start();
}
void mergeSort(int* masiv, int left, int right){
    if (left< right){
        int mid = left +(right -left)/2;
    
        mergeSort(masiv, left, mid);
        mergeSort(masiv, mid+1, right);

        merge(masiv, left,  mid, right);
    }

}

void merge(int* masiv, int left, int mid, int right){
    int lpointer = mid-left+1;
    int rpointer = right- mid;

    int lmasiv[lpointer];
    int rmasiv[rpointer];

    for(int i=0; i< lpointer; i++){
        lmasiv[i] = *(masiv + left+i);
    }
    for(int j =0; j<rpointer; j++){
        rmasiv[j] = *(masiv+mid+1+j);
    }
    int i = 0, j = 0, k = left; 

    while(i< lpointer && j<rpointer){
        if(lmasiv[i]<= rmasiv[j]){
            *(masiv+k) = lmasiv[i];
            i++; 
        }   
        else{
            *(masiv+k) = rmasiv[j];
            j++;
        }
        k++;
    }
    while(i< lpointer){
        *(masiv+k) = lmasiv[i];
        i++;
        k++;
    }

    while(j< rpointer){
        *(masiv+k) = rmasiv[j];
        j++;
        k++;
    }

}//main 
