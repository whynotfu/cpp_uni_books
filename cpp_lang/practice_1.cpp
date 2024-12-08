#include <iostream>
#include <bitset>
#include <cfloat> 


int main(){ //main 
    using namespace std;
    /*FIRST PART*/
    
    cout<< "1. \n Dubina Anastasiia Aleksandrovna, 241-327 \n\n";

    /*SECOND PART*/

    int minInt =  0b10000000000000000000000000000000;
    int maxInt = 0b01111111111111111111111111111111; 

    unsigned int maxUint = 0b11111111111111111111111111111111;

    short maxS = 0b0111111111111111;
    short minS = 0b1000000000000000;

    unsigned short maxUS = 0b1111111111111111;

    long minL =  0b10000000000000000000000000000000;
    long maxL = 0b01111111111111111111111111111111; 

    long long minLL = 0b1000000000000000000000000000000000000000000000000000000000000000;
    long long maxLL = 0b0111111111111111111111111111111111111111111111111111111111111111;
    
    double minD = DBL_MIN;
    double maxD = DBL_MAX;

    float minF = FLT_MIN;
    float maxF = FLT_MAX; 

    char minCh = 0b10;
    char maxCh = 0b01;


    cout<< "2.\n min int = " <<minInt<<  ",\t max int ="<< maxInt<<  ",\t size of int = " << sizeof(int)<<endl;
    cout<< " min unsigned int = 0,\t max unsigned int = "<<maxUint << ",\t  size of unsigned int = "<< sizeof(unsigned int)<<endl;
    cout<< " min short = "<<minS<<   ",\t max short = "<<maxS<< ",\t size of short = "<<sizeof(short)<<endl;
    cout<< " min unsigned short = 0,\t max unsigned short = "<< maxUS<<",\t size of unsigned short = "<< sizeof(unsigned short)<<endl; 
    cout<< " min long = "<<minL<< ",\t max long = "<<maxL<< ",\t size of long = "<< sizeof(long)<<endl; 
    cout<< " min long long = "<< minLL<<",\t max long long = "<<maxLL <<",\t size of long long = "<< sizeof(long long)<<endl;
    cout<< " min double = "<< minD<< ",\t max double = "<< maxD<< ",\t size of double = "<<sizeof(double)<<endl;
    cout<< " min float = "<<minF <<",\t max float = "<< maxF<<",\t size of float = "<<sizeof(float)<<endl;
    cout<< " min char = "<< minCh <<",\t max char = "<<maxCh<< ",\t size of char = "<< sizeof(char)<<"\n\n";

    /*THIRD PART*/
    int num;
    cout<<"3.\n Pic a number: ";
    cin>> num;
    cout <<" In binary " << num<<" is: " << std::bitset<sizeof(num)*8>(num)<<endl;
    cout <<" In hexadecimal " << num<< " is : " << hex<< num<<endl<< dec;
    bool Bnum = num;
    double Dnum = num;
    char Cnum = num; 
    cout << " bool " << Bnum << " \n double " << Dnum << " \n char " << Cnum <<endl;

    /*FORTH PART*/
    int a, b;
    cout <<"\n4.\n Type out the values of \"a\" and \"b\" for a*x=b \n";
    cout << " a = ";
    cin >> a;
    cout << "\n b = ";
    cin >> b;
    cout << " Solution is: \n"<< a<< " * x = "<< b<< endl;
    cout << " x = "<< b<<" / "<< a<<endl;
    cout << " x = "<< b/a<< endl;
    cout<< " The answer is: "<< float(b)/a; // теряются данные из-за int формата, если нужна точность то 1.*b/a

    /*FIFTH PART*/
    int f1,f2; 
    cout<< " Enter the coordinates of the line segment \n 1st: ";
    cin >>f1;
    cout<< " 2nd: ";
    cin >> f2;
    cout<<"The middle of the line is: "<< 1.*(f2+f1)/2; // 
    



}