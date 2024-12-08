
// C:\Users\nasty\Desktop\POLITECH\change.txt

#include <iostream>
#include <string>
#include <cstdio>
#include <filesystem>
#include <fstream> 


void start(void);  // функция меню
std::string file_format(const std::string);
std::string file_name(const std::string);
std::string file_path (const std::string);

char file_disk(const std::string); 
bool file_rename(std::string);
bool file_copy(const std::string);

std::string* split(std::string);
int globalSsize = 0;
//Главная фунция. возврощает репор о состоянии выполнения кода 
int main(){
    start(); // вызов меню 
    return 0;  // еолбэк о состоянии выполнения программы 
}

void start(){
   using namespace std; 
   int chose; // номер функции 
   std::string location; // строка с локацией 
   cout<<"Chose what you want to do: \n\t1. Check extensions of file  \n\t2. Find name of file  \n\t3. Find derection of the file \n\t4. Find the name of disck \n\t5. Rename the file \n\t6. Create a copy \n\t7. Exit:)\n";
   cin>> chose; //ввод номера функции 
   cout<<"Write the location of your file: ";
   cin>>location; //локация файла 
   switch (chose) { // входные данные - номер функции целочисленные
   case 1:      // расширерние найти  
      cout<<file_format(location)<<'\n'; //входные данные - строка, вывод - другая строка 
      start(); // возврат в меню
      break;  
   case 2:
      cout<< file_name(location)<<'\n'; //входные данные - строка, вывод - другая строка 
      start(); // возврат в меню
      break;
   case 3:
      cout<<file_path(location)<<'\n'; //входные данные - строка, вывод - другая строка 
      start(); // возврат в меню
      break;
   case 4:
      cout<<file_disk(location)<<'\n'; //входные данные - строка, вывод - другая строка 
      start(); // возврат в меню
      break;
   case 5:
      file_rename(location); 
      cout<<'\n';
      start(); // возврат в меню
      break;
   case 6:
      if (file_copy(location)){ // если файл создали
         cout<<"You've just created a new file";
      }
      else{
         cout<<"Something went wrong"; //что-то пошло не так(
      }
      cout<<'\n';
      start(); // возврат в меню
      break;
   case 7: //выход 
      cout<<"Thank you!:)\n";
      break;
   default:  //что-то не так
      cout<<"You did something wrong!\n";
      break;
   }
}

std::string file_format(const std::string file_path_full){ // входные данные - строка (путь к файлу)
   
   size_t dot_pos = file_path_full.find_last_of('.'); // находим кол-во символов после точки (целочисленные)
   if (dot_pos == std::string::npos) { // проверка на пустоту строки 
      return "Error"; // определение ошибки 
   }
   return file_path_full.substr(dot_pos); //возвращает подстроку формата строки 
}

std::string file_name(const std::string file_path_full){ // входные данные - строка (путь к файлу)
   std::string* m = split(file_path_full);  //массив с поэтапным разделением пути файла
   std::string name = *(m+globalSsize);  //нахождение части (последней) с записью названия файла 
   delete[] m;  //удаление динамического массива 
   for(int i = 0; i<name.size(); i++){ // проходимя по части с названием 
      if(name[i] =='.'){   // пока нет точки идем  
         name = name.substr(0, i); //нахождение подстроки из строки с названием + расширением => название 
      }
   }
   if (!name.empty()){ //проверка на пустую строку

      return name; //возвращаем новую строку 
   }
   else{
      return "Error"; //ошибка 
   }
}

std::string file_path (const std::string file_path_full){  // входные данные - строка (путь к файлу)
   std::string* m = split(file_path_full);  // массив с поэтапным разделением пути файла
   std::string path = ""; // пыстая строка 
   for(int i = 0; i<(globalSsize); i++ ){ // проходит по всему массиву до последней части с именем файла 
      path += *(m+i); //дописываем в пустую строку данные положения 
   }
   delete[] m; 
   if (!path.empty()){
      return path;  // возвращает путь к файлу - строка 
   }
   else{
      return "Error";  //ошибка 
   }
 // удаление динамического массива 
   return path; // возвращаем строку с путем к файлу 
}
char file_disk (const std::string file_path_full) { //  входные данные - строка (путь к файлу)
   std::string* m = split(file_path_full); // массив с поэтапным разделением пути файла
   std::string disckSTR = *m; // назначакм строке значение первого элемента массива (диск)
   if (!disckSTR.empty()){
      char disc = disckSTR[0];  // назначем символ 
      return disc; // возвращаем символ
   }
   else{
      return '\0'; // возвращеет нуливой символ
   }
}
bool file_rename(std::string file_path_full){ //  входные данные - строка (путь к файлу)
   std::string newname;  //инициализация строки для нового имени 
   std::cout<<"Enter new name of file: ";  
   std::cin>>newname;  // присваивание нового имени 
   if((!newname.empty()) && (!file_path(file_path_full).empty() )){ //проверка на пустую строку и пустой путь 
      std::cout<< file_path(file_path_full)<<newname<<file_format(file_path_full)<<'\n'; //вовод строки с новым названием файла 
      return true; // возвращаем что все прошло хорошо 
   }
   else{ //не на что переименовывать 
      return false;  //возвращаем, что не переименованно
   }
}

bool file_copy(const std::string file_path_full){ //  входные данные - строка (путь к файлу)
   std::ifstream inputFile(file_path_full, std::ios::binary);  // (а) Открытие файла для чтения в бинарном режиме
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file: " << file_path_full << std::endl;
        return false;  // Если файл не открылся, возвращаем false
    }

   std::string copyFilePath = file_path(file_path_full)+file_name(file_path_full)+ "_copy" + file_format(file_path_full);  // Получаем имя файла с добавлением суффикса "_copy"
   
   std::ofstream outputFile(copyFilePath, std::ios::binary);  // Открытие файла для записи в бинарном режиме
   if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to create a copy of the file: " << copyFilePath << std::endl;
        return false;  // Если не удалось создать копию файла, возвращаем false
   }
   outputFile << inputFile.rdbuf();  // построчное копирование содержимого в файле 
   inputFile.close();
   outputFile.close(); // закрытие файлов 
   return true;  
}

std::string* split(std::string file_path_full){
   std::string* parts = new std::string[20];
   std::string temp = ""; 
   int j =0;
   for(int i = 0; i< file_path_full.size(); i++){
      temp+= file_path_full[i];
      if(file_path_full[i] == '\\'){
         parts[j] = temp;
         j++;
         temp.clear();
      }  
      else{
         parts[j] = temp; 
      }
   }
   std::cout<<"\n";
   globalSsize = j;
   return parts; 
}
