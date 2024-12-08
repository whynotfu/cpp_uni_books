#include <iostream>
void start(void);
void triangle(void);
void biom(int);
void arithmeticV(void);
// void exit();

int main(){
    start();
}

void start(){
    using namespace std;
    int numOfOper; 
    cout<<"Welcome to the program \n Choose the function: \n 1. Draw a triangle \n 2. Find Biom \n 3. Find arithmetic .... \n 4. Exit :) \n";
    cin>> numOfOper;
    switch(numOfOper){
        case 1:
            triangle();
            break;
        case 2:
            int n; 
            cout<<"Choose the number n: ";
            cin>>n;
            biom(n);
            break; 
        case 3:
            arithmeticV();
            break;
        case 4: 
            cout<<"Thank you :)";
            break; 
        default:
            cout<<"Thank you :) ";
            break;
    }
}

void triangle(){
    std::cout<<"Choose the number: ";
    int size;
    std::cin>>size;
    for(int i=0; i<=size; i++){
        for(int j=0; j<=i;j++){
            std::cout<<j;
        }
        std::cout<< "\n";
    }
    start();
}
/*
float fucterN(int n){
    float fuctN =1;
    for(int i = 1; i<=n; i++){
        fuctN *= i;
    }
    return fuctN;
}*/

void biom(int n){
    double koef= 1;
    for(int k =0; k<=n; k=k+1){
        std::cout<< koef<< " ";
        koef = (koef * (n - k))/(k+1);
    }
    std::cout<<std::endl;
    start(); 
}
void arithmeticV(){
    int x= 1; 
    int count = 0;
    int sum =0;
    while(x != 0){
        std::cout<<"Give me some number: ";
        std::cin>>x;
        if(x!=0){
         count++;
        }
        sum+=x;
    }
    std::cout<<"The answer is "<<1.*sum/count<< std::endl<< std::endl; 
    start();

} // new
// void exit(){
//     std::cout<<" pop";
// }