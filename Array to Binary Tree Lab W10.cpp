#include <iostream>
using namespace std;

// ---------- 1. Tree Node ----------
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

// ---------- 2. Insert ----------
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    } else {
        cout << "Value already exists in the tree.\n";
    }

    return root;
}

// ---------- 3. Traversals ----------
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

// ---------- 4. Find minimum (used in delete) ----------
Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// ---------- 5. Delete ----------
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // found it
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    return root;
}

// ---------- 6. Update (delete old, insert new) ----------
Node* updateNode(Node* root, int oldValue, int newValue) {
    root = deleteNode(root, oldValue);
    root = insertNode(root, newValue);
    return root;
}

// ---------- 7. Free memory ----------
void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// ---------- 8. Main with SAFETY CHECKS ----------
int main() {
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Insert value\n";
        cout << "2. Delete value\n";
        cout << "3. Update value\n";
        cout << "4. Show traversals\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            // if user types something weird (like a letter), reset input
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a NUMBER between 1 and 5.\n";
            continue;
        }

        if (choice == 1) {
            int x;
            cout << "Enter value to insert: ";
            cin >> x;
            root = insertNode(root, x);
        }
        else if (choice == 2) {
            if (root == nullptr) {
                cout << "Tree is empty. Unable to perform delete.\n";
                continue;
            }
            int x;
            cout << "Enter value to delete: ";
            cin >> x;
            root = deleteNode(root, x);
        }
        else if (choice == 3) {
            if (root == nullptr) {
                cout << "Tree is empty. Unable to perform update.\n";
                continue;
            }
            int oldVal, newVal;
            cout << "Enter value to change: ";
            cin >> oldVal;
            cout << "Enter new value: ";
            cin >> newVal;
            root = updateNode(root, oldVal, newVal);
        }
        else if (choice == 4) {
            if (root == nullptr) {
                cout << "Tree is empty. Unable to perform traversal.\n";
                continue;
            }
            cout << "Inorder   : ";
            inorder(root);
            cout << "\nPreorder  : ";
            preorder(root);
            cout << "\nPostorder : ";
            postorder(root);
            cout << "\n";
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice. Please pick 1–5.\n";
        }
    }

    freeTree(root);
    return 0;
}
