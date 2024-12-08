#include <iostream>
#include <climits>
int main(){
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong =LLONG_MAX;
    cout<< "INT MAX: "<<n_int << '\t'<<"INT: "<< sizeof(int)<< endl;
    cout<< "SHORT MAX: "<<n_short << '\t'<<"SHORT: "<< sizeof(short)<< endl; 
    cout<< "LONG MAX: "<<n_long << '\t'<<"LONG: "<< sizeof(long)<< endl;
    cout<< "LLMAX MAX: "<<n_llong << '\t'<<"LLong: "<< sizeof(long long)<< endl; 
    cout<< CHAR_BIT<< endl;
    return 0;

}