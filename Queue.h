#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

class Queue {
    private:
        node* rear;
        node* front;

    public:
        Queue();
        void enqueue();
        void dequeue();
        void print();



};

#endif // Queue
