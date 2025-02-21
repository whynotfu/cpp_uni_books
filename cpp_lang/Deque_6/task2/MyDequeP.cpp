#include "MyDequeP.h"

// Конструктор
DequePoint::DequePoint() : front(nullptr), back(nullptr), size(0) {}

// Деструктор
DequePoint::~DequePoint() {
    clear();
}

// Добавление в начало
void DequePoint::pushFront(Point p) {
    Node* newNode = new Node(p);
    if (isEmpty()) {
        front = back = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

// Добавление в конец
void DequePoint::pushBack(Point p) {
    Node* newNode = new Node(p);
    if (isEmpty()) {
        front = back = newNode;
    } else {
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
    }
    size++;
}

// Удаление из начала
void DequePoint::popFront() {
    if (isEmpty()) return;
    Node* temp = front;
    front = front->next;
    if (front) front->prev = nullptr;
    else back = nullptr;
    delete temp;
    size--;
}

// Удаление с конца
void DequePoint::popBack() {
    if (isEmpty()) return;
    Node* temp = back;
    back = back->prev;
    if (back) back->next = nullptr;
    else front = nullptr;
    delete temp;
    size--;
}

// Получить первый элемент
Point DequePoint::getFront() {
    return front ? front->data : Point{-1, -1}; // Возвращаем (-1, -1) если пусто
}

// Получить последний элемент
Point DequePoint::getBack() {
    return back ? back->data : Point{-1, -1};
}

// Проверка на пустоту
bool DequePoint::isEmpty() {
    return size == 0;
}

// Получить размер дека
int DequePoint::getSize() {
    return size;
}

// Очистка дека
void DequePoint::clear() {
    while (!isEmpty()) popFront();
}
