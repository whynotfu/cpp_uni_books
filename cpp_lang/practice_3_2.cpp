#include <iostream>

void start(int *, int);

int* create(int); 
void output(int*, int);
int* sort1(int*, int); 
int* sort2(int*, int);
int count(int);
int find(int);


int main(){
    int* arr =nullptr;
    int size = 0; 
    start(arr, size);

    return 0;

}

void start(int* arr, int size){
    using namespace std; 
    cout<< "Chose what you want to do: \n\t1. Enter Massive \n\t2. Read Massive \n\t3. Sort Massive by summ \n\t4. Sort Massive by last digit\n\t5. Exit :)\n";
    int numOfOp;
    cin>>numOfOp;

    switch(numOfOp){
        case 1:

            cout<<"Enter the lenght of your array: ";
            cin>>size;
            arr = create(size);
            start(arr, size);
            break;
        case 2:
            output(arr, size);
            break; 
        case 3: 
            sort1(arr, size);
            start(arr, size);
            break; 
        case 4:
            sort2(arr, size);
            start(arr, size);
            break;
        case 5:
            cout<<"Thank you :)";
            delete[] arr;
            break;
        default:
            cout<<"Invalid option. Try again! ";
            start(arr, size);
            break;
    }
    cout<<endl;
}

int* create(int size){
    int* arr = new int[size];
    std::cout<<"Enter your "<<size<< " numbers:";
    for(int i = 0; i< size; i++){
        std::cin>> arr[i]; 
    }
    std::cout<<std::endl;
    return arr;
}

void output(int* arr, int size){
    using namespace std; 
    cout<<"Your array is:\n";
    for(int i = 0; i< size; i++){
        cout<< *(arr + i)<< "\t";
    }
    cout<<endl;
    start(arr, size);
}

int* sort1(int* arr, int size){
    int m[size];
    for (int i = 0; i<size; i++){
        m[i] =  count(*(arr+i));
    }

    bool is_sorted = false;
    while( is_sorted == false){
        int i =0;
        is_sorted = true; 

         while(i < size-1){
            if(m[i]> m[i+1]){
                int tmp = m[i];
                int tmp2 = *(arr+i);
                m[i] = m[i+1];
                m[i+1] = tmp;
                *(arr + i) = *(arr + i +1);
                *(arr + i +1) = tmp2;
                is_sorted = false;
             }
             i++;
        }

    }

    return arr;
   
}
int count(int number){
    bool even= false; 
    int sum =0;

    while(number>0){
        int digit  = number %10;
        if(even == true){
            sum += digit; 
            even = false;
        }
        else{
            even = true;
        }
        number /= 10;
    }
    return sum; 
}


int * sort2(int * arr, int size){
    int m[size];
    for(int i =0; i<size; i++){
        m[i] = find(*(arr+i));
    }

    bool is_sorted = false;
    while( is_sorted == false){
        int i =0;
        is_sorted = true; 

         while(i < size-1){
            if(m[i]> m[i+1]){
                int tmp = m[i];
                int tmp2 = *(arr+i);
                m[i] = m[i+1];
                m[i+1] = tmp;
                *(arr + i) = *(arr + i +1);
                *(arr + i +1) = tmp2;
                is_sorted = false;
             }
            else if(m[i]==m[i+1]){
                 if(*(arr+i)>(*(arr+i+1))){
                    int nop = m[i];
                    int nop2 = *(arr+i);
                    m[i] = m[i+1];
                    m[i+i]= nop;

                    *(arr+i) = *(arr+i+1);
                    *(arr+i+1) = nop2;
                 }
             }
             i++;
        }

    }
    return arr;
}
int find(int number){
    return number%10;
}