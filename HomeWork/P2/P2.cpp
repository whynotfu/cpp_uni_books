#include <iostream>
#include <string>

void TimeManager(int, int);
double SunTOAstrology(double);
double CelTOFar(int);
void first(void);
void Sec(void);

int main(){
    using namespace std;
    int hours;
    int minutes;
    cout<< "Enter the number of hours: ";
    cin>> hours;
    cout<< "Enter the number of minutes: ";
    cin >> minutes;
    TimeManager(hours, minutes);
    return 0;
}
void TimeManager(int hours, int min){
    std::cout<< "Time: "<< hours<<":"<< min<< std:: endl;
}

void F6(){
    using namespace std;
    double Ly;
    cout<< "Enter the number of light years: ";
    cin>>Ly;
    double Ay = SunTOAstrology(Ly);
    cout << Ly <<" light years  = "<< Ay << " astronomical units."; 
}

double SunTOAstrology(double Ly){
    return 63240*Ly;
}
void F5(){
    using namespace std;
    int celc;
    cout<< "Please enter a Celsius value: ";
    cin >> celc;
    double far = CelTOFar(celc);
    cout<< celc<< " degrees Celsius is "<< far << " degrees Fahrenhait."<< endl;
}
double CelTOFar(int cel){
    return 1.8*cel+32;

}
void AgeTOMonths(){
    using namespace std;
    int age;
    cout<< "Enter your age: ";
    cin  >> age;
    cout<< "Your age in months is "<< age*12<< "."<< endl;

}
void Mice(){
    first();
    first();
    Sec();
    Sec();
}

void first(){
    std::cout<< "Three blind mice"<< std::endl;

}
void Sec(){
    std::cout<<"See how they run"<< std::endl;
}
void NameAndAdress(){
    using namespace std;
    string Name;
    string Adress;
    cin>> Name>> Adress;
    cout<< "Your name is " << Name <<". You live in "<< Adress<<"."<< endl;

}
void JardsAndFarlongs(){
    using namespace std;
    double Farlon;
    cin>> Farlon; 
    cout<<"This "<< Farlon*220<< " jard."<<endl;   

}
