#include <iostream>
#include <string>
using namespace std;

struct node{
    double info;
    struct node *next;
};

class Queue{
    private:
        node *rear;
        node *front;
    public:
        Queue();
        void enqueue();
        void dequeue();
        void print();
};

Queue::Queue(){
    rear = NULL;
    front = NULL;
}

void Queue::enqueue(){
    int data;
    node *temp = new node;
    cout<<"Enter the data to enqueue: ";
    cin>>data;
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
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        front = front->next;
        cout<<"The data Dequeued is "<<temp->info;
        delete temp;
    }
}

void Queue::print(){
    node *p = new node;
    p = front;
    if(front == NULL){
        cout<<"\nNothing to Display\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->next;
        }
    }
}

template <class some_type>
class Stack {
    private:
        int size;
        some_type* data;
        int top;

    public:
        Stack();
        Stack(int);
        bool is_empty();
        bool is_full();
        int get_top();
        some_type get_peek();
        Stack push(some_type);
        some_type pop();
        void print_stack();
        ~Stack();
};

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
        for (int i = 0; i < this->top+1; i++) {
            cout << data[i] << endl;
        }
    }

    template <class some_type>
    Stack<some_type>::~Stack() {}

int main() {

    int choice;
    cout << "Choose the ADT you want to work on" << endl;
    cout << "1. Stack" << endl << "2. Queue" << endl;
    cin >> choice;

    if (choice == 1) {

        int s;
        cout << "Enter stack size: ";
        cin >> s;

        Stack<double> S(s);

        string operation;
        string answer = " ";
        while (true) {
            cout << "Choose the operation you want to perform" << endl;
            cout << "1. Get the index of the top element of the stack" << endl << "2. Get the top element of the stack" << endl << "3. Push an element into the stack" << endl << "4. Pop the top element of the stack" << endl << "5. Print the stack" << endl;

            cin >> operation;
            if (operation == "1") {
                if (S.is_empty() == true) {
                    cout << "Error. Stack is empty." << endl;
                }
                else {
                    cout << "The top element of the stack has index: " << S.get_top()+1 << endl;
                }
            }
            else if (operation == "2") {
                S.get_peek();
            }
            //Here I used another approach than that in TutorialsPoint. I first check if the stack is full and then decide
            //whether to call the push function or not, otherwise in case we had an empty stack, the user would input the
            //value s/he wanted to push, then the program would say that the stack is full, making the input meaningless.
            else if (operation == "3") {
                if (S.is_full() == false) {
                    double d;
                    cout << "Enter the element you want to push: ";
                    cin >> d;
                    S.push(d);
                    cout << "The new element was pushed into the stack" << endl;
                }
                else {
                    cout << "Error. Stack is full." << endl;
                }
            }
            else if (operation == "4") {
                S.pop();
                cout << "The top element of the stack was popped" << endl;
            }
            else if (operation == "5") {
                S.print_stack();
            }

            if (operation != "1" && operation != "2" && operation != "3" && operation != "4" && operation != "5") {
                cout << "The number is not valid" << endl;
            }

            while(answer != "yes" || answer != "no") {
                cout << "Do you wish to perform more operations on the current stack? : ";
                cin >> answer;

                if (answer == "yes") {
                    break;
                }
                else if (answer == "no") {
                    cout << "Thanks for using this tool!!!";
                    break;
                }
                else {
                    cout << "Command not recognized. Try entering yes or no" << endl;
                }
            }
            if (answer == "no") {
                    break;
            }
        }
    }

    else if (choice == 2) {

        Queue Q;

        string operation;
        string answer = " ";
        while (true) {
            cout << "Choose the operation you want to perform" << endl;
            cout << "1. Enqueue" << endl << "2. Dequeue" << endl << "3. Print the queue" << endl;

            cin >> operation;
            if (operation == "1") {
                Q.enqueue();
            }
            else if (operation == "2") {
                Q.dequeue();
            }
            else if (operation == "3") {
                Q.print();
            }

            if (operation != "1" && operation != "2" && operation != "3" && operation != "4") {
                cout << "The number is not valid" << endl;
            }

            while(answer != "yes" || answer != "no") {
                cout << "Do you wish to perform more operations on the current stack? : ";
                cin >> answer;

                if (answer == "yes") {
                    break;
                }
                else if (answer == "no") {
                    cout << "Thanks for using this tool!!!";
                    break;
                }
                else {
                    cout << "Command not recognized. Try entering yes or no" << endl;
                }
            }
            if (answer == "no") {
                    break;
            }
        }
    }
}
