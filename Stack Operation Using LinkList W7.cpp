#include <iostream>
using namespace std;

// Each "box" that keeps a number
struct Node {
    int data;      // the number inside the box
    Node* next;    // pointer to the next box
};

// The Stack class
class Stack {
private:
    Node* top;  // points to the top box

public:
    // When we start, the stack is empty
    Stack() {
        top = NULL;
    }

    // push() = put a new number on top of the stack
    void push(int x) {
        // create a new box
        Node* newBox = new Node();
        newBox->data = x;        // store the number
        newBox->next = top;      // the new box points to the old top
        top = newBox;            // now this new box becomes the new top

        cout << x << " pushed into stack." << endl;
    }

    // pop() = remove the top number
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty! Nothing to pop." << endl;
        } else {
            cout << top->data << " popped from stack." << endl;
            Node* temp = top;      // remember the top box
            top = top->next;       // move the top down to the next box
            delete temp;           // throw away the old top box
        }
    }

    // peek() = look at the top number without removing it
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element is: " << top->data << endl;
        }
    }

    // isEmpty() = check if the stack is empty
    bool isEmpty() {
        return (top == NULL);
    }
};

// Main program: this is where the story begins!
int main() {
    Stack s;  // make a new stack (empty at first)

    s.push(10);  // put 10 on top
    s.push(20);  // then put 20
    s.push(30);  // then 30

    s.peek();    // look at the top number

    s.pop();     // remove 30
    s.pop();     // remove 20
    s.pop();     // remove 10
    s.pop();     // oh no! it’s already empty!

    if (s.isEmpty()) {
        cout << "Stack is empty now." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
