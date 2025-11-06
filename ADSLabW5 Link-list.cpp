#include <iostream>
using namespace std;

struct Node {
    string data;   // text inside the box
    Node* ptr;     // pointer (arrow) to next box
};

int main() {
    // Step 1: Make 3 boxes
    Node node1 = Node();
    Node node2 = Node();
    Node node3 = Node();

    // Step 2: Put data and connect them like a train
    node1.data = "test1";
    node1.ptr = &node2;

    node2.data = "test2";
    node2.ptr = &node3;

    node3.data = "test3";
    node3.ptr = NULL;  // last one has no next box

    // Step 3: Start from the first box
    Node* current = &node1;

    // Step 4: Keep moving through boxes until there’s no next box
    while (current != nullptr) {
        cout << current->data << " ";  // print what’s inside the box
        current = current->ptr;        // move to the next box
    }

    cout << endl; // just go to a new line at the end
    return 0;
}
