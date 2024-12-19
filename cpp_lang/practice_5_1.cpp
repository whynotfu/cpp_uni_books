#include <iostream>



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

class matr
{
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
    
    
};



int main(){



}