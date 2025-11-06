#include <iostream>
using namespace std;

#define MAX 5   // maximum size of the queue

class Queue {
private:
    int arr[MAX];   // array to hold queue elements
    int front, rear;  // front = first element, rear = last element

public:
    Queue() {       // constructor
        front = -1;
        rear = -1;
    }

    // enqueue(): add element to queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << x << endl;
        } else {
            if (front == -1)  // first element being inserted
                front = 0;
            rear++;
            arr[rear] = x;
            cout << x << " enqueued into queue." << endl;
        }
    }

    // dequeue(): remove element from queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to dequeue." << endl;
        } else {
            cout << arr[front] << " dequeued from queue." << endl;
            if (front == rear) {   // queue becomes empty after removing
                front = -1;
                rear = -1;
            } else {
                front++;
            }
        }
    }

    // peek(): see front element without removing
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    // isFull(): check if full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // isEmpty(): check if empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};

int main() {
    Queue q;  // create a queue object

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();  // trying to dequeue when empty

    q.isEmpty() ? cout << "Queue is empty now." << endl
                : cout << "Queue is not empty." << endl;

    return 0;
}
