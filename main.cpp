#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

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
