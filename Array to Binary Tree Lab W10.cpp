#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

// function to build tree
Node* buildTree(const vector<int>& arr, int index) {
    // if index is outside the array, stop
    if (index >= arr.size()) {
        return NULL;
    }

    // Create a new node using the value in the array
    Node* root = new Node(arr[index]);

    // Build left child
    root->left = buildTree(arr, 2 * index + 1);

    // Build right child
    root->right = buildTree(arr, 2 * index + 2);

    return root;
}

// print the tree inorder (small → big)
void printTree(Node* root) {
    if (root == NULL) return;

    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node* root = buildTree(arr, 0);

    cout << "Tree (inorder): ";
    printTree(root);
    cout << endl;

    return 0;
}
