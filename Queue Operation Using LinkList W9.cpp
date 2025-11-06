#include <iostream>
using namespace std;

// Each "box" in the queue
struct Node {
    int data;      // the number inside the box
    Node* next;    // pointer to the next box
};

// The Queue class
class Queue {
private:
    Node* front;   // points to the first box
    Node* rear;    // points to the last box

public:
    // When we start, the queue is empty
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // enqueue() = add a number at the end of the queue
    void enqueue(int x) {
        Node* newBox = new Node();  // make a new box
        newBox->data = x;
        newBox->next = NULL;        // it will be the last one, so no next

        if (rear == NULL) {         // if queue is empty
            front = rear = newBox;  // front and rear both point to it
        } else {
            rear->next = newBox;    // old rear points to new box
            rear = newBox;          // now rear moves to the new box
        }

        cout << x << " added to queue." << endl;
    }

    // dequeue() = remove a number from the front
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty! Nothing to remove." << endl;
        } else {
            cout << front->data << " removed from queue." << endl;
            Node* temp = front;     // remember the front box
            front = front->next;    // move front to the next box
            delete temp;            // delete the old one

            if (front == NULL) {    // if queue becomes empty
                rear = NULL;        // rear must also be NULL
            }
        }
    }

    // peek() = look at the front element
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element is: " << front->data << endl;
        }
    }

    // isEmpty() = check if the queue has no elements
    bool isEmpty() {
        return (front == NULL);
    }
};

// Main program
int main() {
    Queue q;  // make a queue

    q.enqueue(10);  // 10 joins the line
    q.enqueue(20);  // 20 joins next
    q.enqueue(30);  // 30 joins last

    q.peek();       // look at who’s in front

    q.dequeue();    // 10 leaves
    q.dequeue();    // 20 leaves
    q.dequeue();    // 30 leaves
    q.dequeue();    // oh no! line is empty

    if (q.isEmpty()) {
        cout << "Queue is empty now." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
