#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int num) : data(num), right(nullptr), left(nullptr) {}
};

class BST
{

    Node *root;
    Node *insertHelper(Node *node, int value);
    Node *deleteHelper(Node *node, int value);
    Node *searchHelper(Node *node, int value);
    Node *findMin(Node *node);
    void preOrderDisplayHelper(Node *node);
    void postOrderDisplayHelper(Node *node);
    void inOrderDisplayHelper(Node *node);

public:
    BST() : root(nullptr) {};
    void insert(int val);
    void deleteNode(int val);
    bool search(int val);
    void preOrderDisplay();
    void postOrderDisplay();
    void inOrderDisplay();
};

void BST::insert(int val)
{
    root = insertHelper(root, val);
};

Node *BST::insertHelper(Node *node, int value)
{
    if (node == nullptr)
    {
        Node *newNode = new Node(value);
        return newNode;
    }

    if (value < node->data)
    {
        node->left = insertHelper(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insertHelper(node->right, value);
    }
    return node;
};

bool BST::search(int val)
{
    return searchHelper(root, val);
};
Node *BST::searchHelper(Node *node, int value)
{
    if (node == nullptr || value == node->data)
        return node;
    if (value < node->data)
        return searchHelper(node->left, value);
    if (value > node->data)
        return searchHelper(node->right, value);
};

void BST::deleteNode(int val)
{
    root = deleteHelper(root, val);
};
Node *BST::deleteHelper(Node *node, int value)
{
    if (node == nullptr)
        return node;

    if (value < node->data)
        node->left = deleteHelper(node->left, value);
    else if (value > node->data)
        node->right = deleteHelper(node->right, value);
    else
    { // if value == node ka data
        if (node->right == nullptr)
            return node->left;
        else if (node->left == nullptr)
            return node->right;

        // else if both nodes are there
        Node *temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteHelper(node->right, temp->data);
    }
    return node;
};

Node *BST::findMin(Node *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
};

void BST::preOrderDisplay()
{
    preOrderDisplayHelper(root);
};
void BST::preOrderDisplayHelper(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data << ' ';
    preOrderDisplayHelper(node->left);
    preOrderDisplayHelper(node->right);
}


    void BST::postOrderDisplay(){
        postOrderDisplayHelper(root);
    };
    void BST::inOrderDisplay(){

    };

void BST::postOrderDisplayHelper(Node *node) {
    if(node == nullptr) return;
    postOrderDisplayHelper(node->left);
    postOrderDisplayHelper(node->right);
    cout << node->data << ' ';
};
void BST::inOrderDisplayHelper(Node *node) {

};

int main()
{
    BST binaryTree;
    binaryTree.insert(8);
    binaryTree.insert(3);
    binaryTree.insert(1);
    binaryTree.insert(7);
    binaryTree.insert(4);
    binaryTree.insert(10);
    binaryTree.insert(14);
    binaryTree.insert(13);
    // cout << binaryTree.search(2) << endl;
    // binaryTree.deleteNode(2);
    // cout << binaryTree.search(2) << endl;
    binaryTree.postOrderDisplay();
    return 0;
}