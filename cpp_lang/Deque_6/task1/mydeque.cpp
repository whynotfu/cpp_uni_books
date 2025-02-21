
#include "MyDeque.h"

Deque::Deque() : front(nullptr), rear(nullptr), size(0) {}

Deque::~Deque() {
    while (!isEmpty()) {
        popFront();
    }
}

bool Deque::isEmpty() {
    return size == 0;
}

void Deque::pushFront(char value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

void Deque::pushBack(char value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

void Deque::popFront() {
    if (isEmpty()) {
        std::cerr << "Deque is empty!\n";
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front) {
        front->prev = nullptr;
    } else {
        rear = nullptr;
    }
    delete temp;
    size--;
}

void Deque::popBack() {
    if (isEmpty()) {
        std::cerr << "Deque is empty!\n";
        return;
    }
    Node* temp = rear;
    rear = rear->prev;
    if (rear) {
        rear->next = nullptr;
    } else {
        front = nullptr;
    }
    delete temp;
    size--;
}

char Deque::getFront() {
    if (isEmpty()) {
        std::cerr << "Deque is empty!\n";
        return '\0';
    }
    return front->data;
}

char Deque::getBack() {
    if (isEmpty()) {
        std::cerr << "Deque is empty!\n";
        return '\0';
    }
    return rear->data;
}

int Deque::getSize() {
    return size;
}

void Deque::display() {
    if (isEmpty()) {
        std::cout << "Deque is empty!\n";
        return;
    }
    Node* temp = front;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
