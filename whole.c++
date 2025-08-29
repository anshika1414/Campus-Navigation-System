#include <iostream>
using namespace std;

// AVL Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Function to calculate the height of a node
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}


// Create a new AVL tree node
Node* newNode(int key) {
    Node* node = new Node;
    node->data = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}
Node* newNode(int key){
    Node* node=

    
    ssteynre tem.out,println
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of a node
int balanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Insert a key into the AVL tree
Node* insert(Node* node, int key) {
    // Perform standard BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // Equal keys not allowed

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance factor
    int balance = balanceFactor(node);

    // Rebalance if needed

    // Left Left
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the node with the minimum key value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Delete a node from the AVL tree
Node* deleteNode(Node* root, int key) {
    // Perform standard BST deletion
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one or no child
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            delete temp;
        } else {
            // Node with two children
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance
    int balance = balanceFactor(root);

    // Rebalance if needed

    // Left Left
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 63);
    root = insert(root, 9);
    root = insert(root, 19);
    root = insert(root, 27);
    root = insert(root, 18);
    root = insert(root, 108);
    root = insert(root, 99);
    root = insert(root, 81);

    cout << "In-order traversal of the AVL tree: ";
    inOrder(root);
    cout << endl;

    root = deleteNode(root, 81);
    root = deleteNode(root, 99);
    root = deleteNode(root, 108);
    root = deleteNode(root, 18);
    root = deleteNode(root, 27);
    root = deleteNode(root, 19);

    cout << "In-order traversal of the AVL tree after deletions: ";
    inOrder(root);
    cout << endl;

    return 0;
}
