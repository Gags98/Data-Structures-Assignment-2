#include "Queue.h"
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

    Queue::Queue(){
        rear = NULL;
        front = NULL;
    }

    void Queue::enqueue(){
        int data;
        node *temp = new node;
        cout << "Enter the data to enqueue: ";
        cin >> data;
        temp->info = data;
        temp->next = NULL;
        if(front == NULL){
            front = temp;
        }else{
            rear->next = temp;
        }
        rear = temp;
    }

    void Queue::dequeue(){
        node *temp = new node;
        if(front == NULL){
            cout << "Sorry, but the queue is empty" << endl;;
        }
        else{
            temp = front;
            front = front->next;
            cout << "The dequeued data is " << temp->info;
            delete temp;
        }
    }

    void Queue::print(){
        node *p = new node;
        p = front;
        if(front == NULL){
            cout << "Sorry, but the queue is empty" << endl;
        }
        else{
            while(p!=NULL){
                cout << p->info << endl;
                p = p->next;
            }
        }
    }
