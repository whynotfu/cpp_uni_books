#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <iostream>

class Deque {
private:
    struct Node {
        char data;
        Node* prev;
        Node* next;
        Node(char val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Deque();
    ~Deque();

    bool isEmpty();
    void pushFront(char value);
    void pushBack(char value);
    void popFront();
    void popBack();
    char getFront();
    char getBack();
    int getSize();
    void display();
};

#endif 
