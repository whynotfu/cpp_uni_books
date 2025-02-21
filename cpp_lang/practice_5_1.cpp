#include <iostream>

class matr {
private:
    int rows;
    int cols;
    double* data;

public:
    // Конструктор
    matr(int rows, int cols) {
        if (rows <= 0 || cols <= 0) {
            std::cout << "Error: the size of matrix should be bigger than 0.\n";
            rows = cols = 1;
        }
        this->rows = rows;
        this->cols = cols;
        data = new double[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = 0;
        }
    }

    // Деструктор
    ~matr() {
        delete[] data;
    }

    // Методы доступа
    int get_rows() const { return rows; }
    int get_cols() const { return cols; }

    double get_element(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            std::cout << "Index error\n";
            return 0;
        }
        return data[i * cols + j];
    }

    void set_elem(int i, int j, double value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            std::cout << "Error: out of index.\n";
            return;
        }
        data[i * cols + j] = value;
    }

    // Ввод
    void input() {
        std::cout << "Enter the matrix elements (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cin >> data[i * cols + j];
            }
        }
    }

    // Вывод
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i * cols + j] << " ";
            }
            std::cout << '\n';
        }
    }

    // Сложение
    matr* sum(const matr* mat2) const {
        if (rows != mat2->get_rows() || cols != mat2->get_cols()) {
            std::cout << "Error: matrices dimensions do not match.\n";
            return nullptr;
        }
        matr* result = new matr(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result->data[i] = data[i] + mat2->data[i];
        }
        return result;
    }

    // Умножение
    matr* mult(const matr* mat2) const {
        if (cols != mat2->get_rows()) {
            std::cout << "Error: cannot multiply matrices.\n";
            return nullptr;
        }
        matr* result = new matr(rows, mat2->get_cols());
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < mat2->get_cols(); j++) {
                double sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += get_element(i, k) * mat2->get_element(k, j);
                }
                result->set_elem(i, j, sum);
            }
        }
        return result;
    }

    // Умножение на число
    matr* mult_by_num(double num) const {
        matr* result = new matr(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result->data[i] = data[i] * num;
        }
        return result;
    }

    // След
    double trace() const {
        if (rows != cols) {
            std::cout << "Error: matrix is not square.\n";
            return 0;
        }
        double trace_sum = 0;
        for (int i = 0; i < rows; i++) {
            trace_sum += get_element(i, i);
        }
        return trace_sum;
    }

    // Определитель
    double det() const {
        if (rows != cols) {
            std::cout << "Error: matrix is not square.\n";
            return 0;
        }
        if (rows == 1) {
            return get_element(0, 0);
        }
        if (rows == 2) {
            return get_element(0, 0) * get_element(1, 1) - get_element(0, 1) * get_element(1, 0);
        }

        double determinant = 0;
        for (int j = 0; j < cols; j++) {
            matr minor(rows - 1, cols - 1);
            for (int i = 1; i < rows; i++) {
                int minor_col = 0;
                for (int k = 0; k < cols; k++) {
                    if (k == j) continue;
                    minor.set_elem(i - 1, minor_col, get_element(i, k));
                    minor_col++;
                }
            }
            determinant += (j % 2 == 0 ? 1 : -1) * get_element(0, j) * minor.det();
        }
        return determinant;
    }
};

int main() {
    using namespace std;
    matr m1(2, 2);
    m1.input();

    matr m2(2, 2);
    m2.input();

    matr* sum_result = m1.sum(&m2);
    if (sum_result) {
        cout << "Matrix sum:\n";
        sum_result->print();
        delete sum_result;
    }

    matr* mult_result = m1.mult(&m2);
    if (mult_result) {
        cout << "Matrix multiplication:\n";
        mult_result->print();
        delete mult_result;
    }

    cout << "Trace of the matrix: " << m1.trace() << endl;
    cout << "Determinant: " << m1.det() << endl;

    matr* scaled = m1.mult_by_num(2);
    cout << "Matrix multiplied by 2:\n";
    scaled->print();
    delete scaled;

    return 0;
}