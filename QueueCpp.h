#ifndef Queue_h
#define Queue_h

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node*[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node*[this->size];
    }
    void enqueue(Node * x);
    Node * dequeue();
    int isEmpty() { return front == rear; }
};

void Queue::enqueue(Node * x)
{
    if (rear == size - 1)
    {
        cout << "Queue is full";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node * Queue::dequeue()
{
    Node * x = NULL;
    if (rear == front)
    {
        cout << "Queue is full";
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}



#endif
