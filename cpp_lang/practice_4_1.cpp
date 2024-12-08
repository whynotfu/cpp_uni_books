#include <iostream>
#include <cstring>
// инициализация функций 
void start(void); // меню
bool Palindrom(char*); // проверка на палендром
char toSmall(char); // перевод заглавной буквы в прописную
int* find_substring2(const char *, const char *); // поиск подстрок 
void outParr(int*,  int);  // вывод массива с целыми числами
void encrypt(char*, int ); // шифр Цезаря
void outParrCHAR(char*, int); // вывод масива с символомаи 
void noQoutes(char*); // убрать кавычки

int sizeG; 
int main(){ // глафнвя функция. ввходные данные не нужны. возращает состоянии о команде. 
    start();  // вызывает функцию меню 
    return 0;
}
void start(){  // функция меню. не выводит ничего и не требует никаких выължных данных 
    using namespace std; 
    cout<< "Chose what you want to do: \n\t1. Check Polindrom  \n\t2. Line Search \n\t3. Caesar cipher \n\t4. Out of Quotes!!! \n\t5. Exit :)\n";
    int chose;
    char text[255];  // массив из строк 
    char subsrt[255]; // дополнительный массив из строк для 2й опирации меню
    int* mas = nullptr;

    cin>>chose; // номер выбранной функции

    switch(chose){
        case 1:
            cin.ignore(); // отчистка массива 
            cout<<"Enter string (max 255 char): ";
            cin.getline(text, 256); // считываем строку 
            if (Palindrom(text)){ // вызов функции проверки на палендром 
                cout<<"The stribng is a palindrome!\n"; 
            }
            else{
                cout<<"The string is NOT a palindrome!\n";
            }
            start(); // возврат в меню 
            break;
        case 2: 
            cin.ignore(); // отсчитка массива
            cout<<"Enter your sring (max 255 char): ";
            cin.getline(text, 256); // считываем массив 
            cout<<"Enter your substring (max 255 char): ";
            cin.getline(subsrt, 255); // считываем 2й массив 
            mas = find_substring2(text, subsrt); // вызываем функцию и присваем значение указателя массива 
            outParr(mas, sizeG); // Out Put ARRAy - вывод массива через запятую
            cout<< "\n";
            delete[] mas; // удаление динамическо массива   
            start(); // возвращение меню 
            break;
        case 3:
            cin.ignore(); // отчистка массива 
            cout<<"Enter your sring (max 255 char): ";
            cin.getline(text, 256); // считывем массив 
            cout<<"Enter your key: ";
            int key; // ключ к шифру (сдвиг по ASCII)
            cin>>key; 
            encrypt(text, key); //вызов фунции шифра 
            cout<<'\n';
            start(); //возврат в меню 
            break;
        case 4: 
            cin.ignore(); //отчистка массива 
            cout<<"Enter your sring (max 255 char): ";
            cin.getline(text, 256); // считываение строки 
            noQoutes(text); // вызов фунуукции
            cout<<'\n';
            start(); // меню 
            break;
        case 5: 
            cout<<"Thank you! :)" ; // просто выход
            break; 
        default:
            cout<<"You did something wrong. Try again!";
            break; 

            
    }
}

// требуется символ В диапозоне от A до Z по ASCII, возвращеет аналогичный символ малой буквы
char toSmall(char text){ 
    if(text>='A' && text<='Z'){
        text = text +('a'-'A'); 
    }
    return text; 
}

// на входе требуется указатель на массив, выводит булевое значение в зависимости вляется ли строка палендромом
bool Palindrom(char* text){ 
    bool flag = true; // флаг проверки 
    int len  = strlen(text); // длинна массивы (с- строки )
    
    for (int i = 0, j = len-1; i<j; i++, j--){ // проходится по всему массиву
        if(text[i] == ' '){
            i++; //пропускает пробелы слева
        }
        if(text[j] == ' '){
            j--; //пропускает пробелы справа 
        }
        if(toSmall(text[i]) != toSmall(text[j]) ) {
            flag = false; //если символ справа не равен символу слева, функция ломается и стока автоматически не является палендромом
            break;
        }
    }
    return flag; // возвращает true или false
}
// требует на вход 2 указателя на массив (строки) на сам текст и на подстроку, которую необходимо найти 
int* find_substring2(const char * str_for_search_in, const char * substring){
    int lenText = strlen(str_for_search_in); //длинна текста
    int lenSub = strlen(substring); //длинна подтекста 

    int* arr = new int[256]; // создание динамического массива 
    int ans = 0; // кол-во найденных слова
    for(int i = 0; i<= lenText-lenSub-1; i++){// проходится по главному тексту, без учета подстроки 
        int j; 
        for(j = 0; j<lenSub; j++){
            if (str_for_search_in[i+j] !=  substring[j]){ //если элемент n-й элемент текста не равен элементу подстроки - выход; тк дальше текст тоже не будет равен 
                break;
            }
        }
        if(j == lenSub){ // признак того, что полность есть подстрока в данном тексте 
            arr[ans] = i; // добавляем индекс 1 го символа в массив 
            ans++; 
        }
    }
    sizeG = ans; // размер массива индексов 
    return arr; //возвращаем массив индексов 

}
// требует на вход указатель на целочисленный массив, который необходимо прочитать и его размер. никакие данные не возвращает, выводит в консоль элементы
void outParr(int * mas, int size){ 
    for(int i =0; i< size; i++){ // проходит по всему массиву 
        std::cout<< mas[i];  // вывод в консоль
        if (i!=size-1){
            std::cout<<","; // ставит запятую между каждым элементом массива
        }
    }
}
// требует на вход указатель на символьный массив, который необходимо прочитать и его размер. никакие данные не возвращает, выводит в консоль элементы.
void outParrCHAR(char * mas, int size){ 
    for(int i =0; i< size; i++){
        std::cout<< mas[i]; // вывод в консоль элементы массива
    }
}

// требует на вход указатель на символьный ассив (с- строки) и ключ (сдвиг по ASCII) для шифрования 
void encrypt(char* str_for_encrypt, int key){ 
    int lenText =strlen(str_for_encrypt); // длинна строки
    char* arr = new char[lenText+1]; // созданние динамического массива

    for(int i=0; i<lenText; i++){ // пррход по всему массиву
        if(str_for_encrypt[i] >= 'a' && str_for_encrypt[i]<= 'z'){ // пррверка на текст для маленьких букв
            if(str_for_encrypt[i] + key > 'z'){ 
                arr[i] = char((str_for_encrypt[i] + key - 'a') % 26 + 'a'); // сдвиг по алфавиту ASCII коду 
            }
            else{
                arr[i] = char(str_for_encrypt[i]+key); // к неалфавитному символу просто прибавляем значение ключа 
            }
        }
    
        else if(str_for_encrypt[i] >= 'A' && str_for_encrypt[i] <= 'Z'){  // пррверка на текст для заглавных букв
            if(str_for_encrypt[i] + key > 'Z'){ 
                arr[i] = char((str_for_encrypt[i] + key - 'A') % 26 + 'A');// сдвиг по алфавиту ASCII коду 
            }
            else{
                arr[i] = char(str_for_encrypt[i] + key);// к неалфавитному символу просто прибавляем значение ключа 
            }
        }
        else{
            arr[i] = str_for_encrypt[i]; // остальное неизменяется 
        }

    }
    arr[lenText] = '\0'; // добавляет символ окончания
    std::cout << "Decrypted: ";
    outParrCHAR(arr, lenText); // печатает массив
    delete[] arr; // удаляем динамический массив

}
// требует на вход указатель на массив символов (с-строки)
void noQoutes(char* text){
    int lenText = strlen(text); //длинна строки 
    int start = -1; //начальная позиция проверки 
    bool withQ =false; // флаг на уже наличие открытых 
    for(int i =0; i< lenText; i++){ // проход по всему массиву
        if((text[i] == '"' || text[i] == '<') && !withQ){ // проверяет на наличеи люого рода кавычек 
            start = i++; // 
            withQ = true; // кавычки открыты 
        }
        else if((text[i] == '"' || text[i] == '>') && withQ){
            for(int j = start; j<i; j++){
                std::cout<< text[j]; //вывод текста без кавычек
            }
            std::cout<< " | ";// отделение 
            withQ = false; // кавычки хакрыты 
        }
    }
    std::cout<< "\n";
}