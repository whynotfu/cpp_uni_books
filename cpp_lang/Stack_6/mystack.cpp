#include "MyStack.h"
#include <iostream>

Node::Node(char value) {
    data = value;
    next = nullptr;
}

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(char value) {
    Node* newNode = new Node(value);
    newNode -> next = top;
    top = newNode;
}

void Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

char Stack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is empty!\n";
        return '\0';
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}
