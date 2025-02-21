#ifndef DEQUEPOINT_H
#define DEQUEPOINT_H

#include <iostream>

struct Point {
    int x, y;
};

struct Node {
    Point data;
    Node* next;
    Node* prev;
    Node(Point p) : data(p), next(nullptr), prev(nullptr) {}
};

class DequePoint {
private:
    Node* front;
    Node* back;
    int size;

public:
    DequePoint();
    ~DequePoint();

    void pushFront(Point p);
    void pushBack(Point p);
    void popFront();
    void popBack();
    
    Point getFront();
    Point getBack();
    bool isEmpty();
    int getSize();
    void clear();
};

#endif
