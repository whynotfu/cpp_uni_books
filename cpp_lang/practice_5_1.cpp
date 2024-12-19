#include <iostream>


void start(void);
/*Написать класс матриц. 

Свойства класса: число строк, число столбцов, одномерный динамический массив для хранения элементов.

Реализовать методы 
matr* sum(const matr * mat2) или sum(const matr * mat2) - сложения матриц, 
matr* mult(const matr * mat2) или void mult(const matr * mat2) - умножения двух матриц, 
double trace() - след матрицы (сумма диагональных элементов квадратной матрицы),
double det()  - определитель матрицы (для квадратных),
matr* mult_by_num(double num)  или void mult_by_num(double num)   - умножение матрицы на число,
void input() - ввести матрицу с клавиатуры, 
void print() - печать матрицы в консоль, 
int get_columns() - количество столбцов,
int get_rows() - количество строк
double get_elem(int i, int j) - вернуть (i,j) элемент 
*/

class matr{
private: 
    int rows;
    int cols; 
    double* data; 
    
public:
//конструктор 
    matr(int rows, int cols){
        if (rows <= 0 || cols <= 0){ // проверка на входные данные 
            std::cout<<"Error: the size of matrix should be bigger then 0 \n"; // ошибка отрицательной матрицы или 0 не может быть 
            rows = cols = 1;  // матрица 1х1 
        }
        this -> rows = rows;
        this -> cols = cols; 
        data = new double[rows * cols];
        for(int i = 0; i<rows * cols; i++){
            data[i] = 0;    // инициализация матрицы заполненую нулями 
        }
    }
// деструктор 
    ~matr(){
        delete[] data;
    }
//получение кол-во строк
    int get_rows() const{
        return rows;
    }
// получение кол-во столбцов
    int get_cols() const {
        return cols; 
    }
    //получение элементов i и j
    double get_element(int i, int j) const{
        if(i < 0 || i>= rows || j< 0 || j>cols){
            std::cout<< "INdex error \n";
            return 0;
        }
        return data[i*cols+j];     
    } 

    //ввод
    void input(){
        std::cout<< "Enter the matrix elements ("<< rows << "X"<<cols<<")\n";
        for(int i= 0; i< rows; i++){
            for(int j = 0; j<cols; j++ ){
                std::cin>> data[i*cols+j];
            }
        }  
    }
    //вывод 
    void print() const {
        for(int i =0; i < rows; i++){
            for(int j = 0; j<cols; j++){
                std::cout<< data[i*cols + j ]<< " ";
            }
            std::cout<<'\n';
        }
    }
    matr* sum(const matr* mat2) const{ // =сложение матриц
        if(rows!=mat2 ->get_rows() || cols != mat2 -> get_cols()){
            std::cout<<"Error matrix are not equil. Can not sum it \n";
            return nullptr;
        }
        matr* result = new matr(rows, cols); 
        for(int i = 0; i< rows*cols; i++){
            result -> data[i] + mat2 -> data[i];
        } 
        return result;
    }  

};



int main(){
    start();
    return 0; 
}