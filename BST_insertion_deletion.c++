#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

// Insert function to add a new node
Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = new Node();
        newNode->val = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value <= root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Successor function to find the smallest value node in the right subtree
Node* successorFunction(Node* root) {
    Node* current = root->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete function to remove a node
Node* delete_(Node* root, int target) {
    if (target < root->val) {
        root->left = delete_(root->left, target);
    } else if (target > root->val) {
        root->right = delete_(root->right, target);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* successor = successorFunction(root);
            root->val = successor->val;
            root->right = delete_(root->right, successor->val);
        }
    }
    return root;
}

// Pre-order Traversal (Depth-First Traversal)
void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int arr[7] = {3, 6, 33, 5, 17, 2, 1};
    Node* root = NULL;
    cout << "The numbers passed are: ";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
        root = insert(root, arr[i]);
    }
    cout << "\nPre-Order Traversal (DFT): ";
    preOrder(root);
    cout << endl;

    // Delete a node and show updated traversal
    root = delete_(root, 6);  // Deleting node with value 12
    cout << "Pre-Order Traversal after deleting 6: ";
    preOrder(root);
    cout << endl;

    return 0;
}

