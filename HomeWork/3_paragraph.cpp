#include <iostream>

const double INCH_IN_FEET_KOEF = 1./12;
const double INCH_TO_M = 0.0254; 
const double POUNDS_TO_KG = 2.2;
const double KM_TO_MILES = 62.14;
const double LIT_TO_GAL = 3.875;

void start();
void inchInFeets(void);
void BMIcalculator(void);
void degreesM(void);
void timeCount(void);
void WorldPopulation(void);
void litersPKm(void);
void toUSmesur(void);

int main(){
    start();
    return 0;
}

void start(){
    using namespace std;
    int numOfOper;
    cout<<"Choose operation:\n\t1.Inch in feets\n\t";
    cout<<"Type: _____\b\b\b\b";
    cin>>numOfOper;
    cout<<"\n";
    switch(numOfOper){
        case 1: 
            inchInFeets();
            break;
        case 2:
            BMIcalculator();
            break;
        case 3:
            degreesM();
            break;
        case 4:
            timeCount();
            break;
        case 5:
            WorldPopulation();
            break;
        case 6:
            litersPKm();
            break;
        case 7:
            toUSmesur();
            break;
        default:
            cout<<"Thank you! \n";
            break; 
    }

}
void inchInFeets(){
    double inch;
    std::cout<<"What is the value in inches:____\b\b\b\b";
    std::cin>>inch;
    int feets = inch*INCH_IN_FEET_KOEF;
    std::cout<<"The answer is: "<< feets << " feet(s) " <<  int (inch-feets / INCH_IN_FEET_KOEF)<< " inch(es).\n";
    start();

}
void BMIcalculator(){
    int feet; 
    float inch; 
    int weight;
    std::cout<<"Enter please your hight in feet: ____\b\b\b";
    std::cin>> feet;
    std::cout<<"\tin inches: ____\b\b\b";
    std::cin>> inch;
    std::cout<<"\nEnter please your weight in pounds: ____\b\b\b";
    std::cin>>weight; 
    inch = inch + 1.*feet/INCH_IN_FEET_KOEF;
    double height= inch * INCH_TO_M;
    double mass = weight/POUNDS_TO_KG;
    std::cout<<"Your BMI is: "<< int (mass/(height*height))<< "\n";
    start();

}

void degreesM(){
    using namespace std;
    cout<<"Enter a latitude in degrees, minutes, and seconds:\nFirst, enter the degrees: ";
    int degrees;
    cin>> degrees;
    cout<<"\nNext, enter thr minutes of arc: ";
    int minutes; 
    cin>>minutes;
    cout<<"\nFinally, enter the seconds of arc: ";
    int sec; 
    cin>> sec;
    cout<< degrees<<" degrees, "<<minutes<<" minutes, "<< sec<< " seconds = " << degrees + (minutes)/60. + (sec)/(60*60.)<< "\n";
    start();
}

void timeCount(){
    unsigned long long int timeInsec;
    std::cout<<"Enter the number of seconds: ";
    std::cin>> timeInsec;
    std::cout<<timeInsec<< " seconds = "<< timeInsec/(60*60*24)<<" days, "<<timeInsec/(60*60)-(timeInsec/(60*60*24)*24) <<" hours, "<<(timeInsec/60)- (timeInsec/(60*60)*60) <<" minutes, "<< timeInsec%60<< "\n"; 
    start();
}
void WorldPopulation(){
    unsigned long long int wordP;
    std::cout<<"Enter the world's population: ";
    std::cin>>wordP;
    unsigned long long int countryP;
    std::cout<<"Enter the population of the US: ";
    std::cin>>countryP;
    std::cout<<"The population of the US is "<< 100 * countryP*1./wordP<<"% of the world population\n";
    start();
}
void litersPKm(){
    int km;
    std::cout<<"Enter the numbers of km: ";
    std::cin>> km;
    int volume; 
    std::cout<<"Enter the number of volume: ";
    std::cin>>volume;
    std::cout<<"There is "<< volume/km << " l/km\n";
    start();

}
void toUSmesur(){
    double literPkm;
    std::cout<<"Enter the number of gasoline consumption l/100km: ";
    std::cin>>literPkm;
    std::cout<<"This is about: "<<1/((LIT_TO_GAL / KM_TO_MILES) * (literPkm)) << "\n";
    start();
} 
