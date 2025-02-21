#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
struct Node {
    char data;
    Node* next;
    Node(char value); // конструктор 
};

class Stack {
private:
    Node* top; // укахатель на верхний элемент СТЭКА 

public:
    Stack();
    ~Stack();
    
    void push(char value);
    void pop();
    char peek();
    bool isEmpty();
};

#endif //предотвращая повторное включение заголовочного файла