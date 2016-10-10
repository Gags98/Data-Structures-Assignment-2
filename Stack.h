#ifndef STACK_H
#define STACK_H

template <class some_type>
class Stack {
    private:
        int size;
        some_type* data;
        int top;

    public:
        Stack();
        Stack<some_type>(int);
        bool is_empty();
        bool is_full();
        int get_top();
        some_type get_peek();
        Stack push(some_type);
        some_type pop();
        void print_stack();
        ~Stack();
};

#endif // STACK_H
