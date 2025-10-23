#include <iostream>
using namespace std;

#define MAX 5   // maximum size of the stack

class Stack {
private:
    int arr[MAX];   // array to hold stack elements
    int top;        // points to the top element

public:
    Stack() {       // constructor
        top = -1;   // empty stack when top = -1
    }

    // push(): add element to stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << x << endl;
        } else {
            top++;
            arr[top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    // pop(): remove element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to pop." << endl;
        } else {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    // peek(): see top element without removing
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // isFull(): check if full
    bool isFull() {
        return (top == MAX - 1);
    }

    // isEmpty(): check if empty
    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack s;  // create a stack object

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();

    s.pop();
    s.pop();
    s.pop();
    s.pop();  // trying to pop when empty

    s.isEmpty() ? cout << "Stack is empty now." << endl
                : cout << "Stack is not empty." << endl;

    return 0;
}
