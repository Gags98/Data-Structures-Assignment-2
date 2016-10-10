#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

    template <class some_type>
    Stack<some_type>::Stack() {
        size = 0;
        data = new some_type[size];
    }

    template <class some_type>
    Stack<some_type>::Stack(int i) {
        size = i;
        data = new some_type[i];
        for (int i = 0; i < size; i++) {
            data[i] = NULL;
        }
        top = -1;
    }

    template <class some_type>
    bool Stack<some_type>::is_empty() {
        if (this->top < 0) {
            return true;
        }
        else {
            return false;
        }
    }

    template <class some_type>
    bool Stack<some_type>::is_full() {
        if (this->top == size-1) {
            return true;
        }
        else {
            return false;
        }
    }

    template <class some_type>
    int Stack<some_type>::get_top() {
        for (int i = size-1; i >= 0; i--) {
            if (data[i] != NULL) {
                top = i;
                return top;
            }
        }
    }

    template <class some_type>
    some_type Stack<some_type>::get_peek() {
        if (this->is_empty()) {
            cout << "Error. The stack is empty." << endl;
        }
        else {
            return this->data[this->get_top()];
        }
    }

    template <class some_type>
    Stack<some_type> Stack<some_type>::push(some_type d) {
        top++;
        data[top] = d;
        return *this;
    }

    template <class some_type>
    some_type Stack<some_type>::pop() {
        if (this->is_empty()) {
            cout << "Error. Stack is empty." << endl;
            return 0;
        }
        else {
            data[top] = NULL;
            top--;
            return data[top];
        }
    }

    template <class some_type>
    void Stack<some_type>::print_stack() {
        cout << "Here is the stack" << endl;
        for (int i = 0; i < this->top; i++) {
            cout << data[i] << endl;
        }
    }

    template <class some_type>
    Stack<some_type>::~Stack() {}
