#include "MyDequeP.h"
#include <iostream>


// Определение ориентации трех точек
int orientation(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

// Пузырьковая сортировка точек относительно `R`
void sortPoints(Point points[], int n, const Point& R) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (orientation(R, points[j], points[j + 1]) < 0) {
                std::swap(points[j], points[j + 1]); //сортирует точки так, чтобы их можно было правильно соединить в выпуклую оболочку
            }
        }
    }
}

// Поиск выпуклой оболочки
void convexHull(Point points[], int n) {
    if (n < 3) return;

    //  Находим самую левую точку
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[minIdx].x || (points[i].x == points[minIdx].x && points[i].y < points[minIdx].y)) {
            minIdx = i;
        }
    }
    std::swap(points[0], points[minIdx]);
    Point R = points[0];

    // Сортируем точки по углу
    sortPoints(points, n, R);

    // Строим выпуклую оболочку
    DequePoint hull;
    hull.pushBack(points[0]);
    hull.pushBack(points[1]);

    for (int i = 2; i < n; i++) {
        while (hull.getSize() > 1) {
            Point second = hull.getBack();
            hull.popBack();
            Point first = hull.getBack();
            if (orientation(first, second, points[i]) > 0) { // Левый поворот
                hull.pushBack(second);
                break;
            }
        }
        /*Если правый поворот, удаляем предпоследнюю точку.
Если левый поворот, оставляем её.*/
        hull.pushBack(points[i]);
    }

    // Вывод результата
    std::cout << "DOTS:\n";
    while (!hull.isEmpty()) {
        Point p = hull.getFront();
        std::cout << "(" << p.x << ", " << p.y << ")\n";
        hull.popFront();
    }
}

int main() {
    const int SIZE = 5;
    Point points[SIZE] = {{0, 0}, {4, 4}, {1, 2}, {3, 0}, {4, 0}};
    convexHull(points, SIZE);
    return 0;
}
