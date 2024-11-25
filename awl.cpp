#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    int height;
    Node(int num) : data(num), right(nullptr), left(nullptr), height(1) {}
};

class AWL
{

    Node *root;
    int height(Node *node);
    int getBalancingFactor(Node *node);
    Node *leftRotation(Node *node);
    Node *rightRotation(Node *node);
    Node *insertHelper(Node *node, int val);
    bool searchHelper(Node *node, int val);

public:
    AWL() : root(nullptr) {};
    void insert(int val);
    bool search(int val);
};
void AWL::insert(int val)
{
    root = insertHelper(root, val);
}
Node *AWL::insertHelper(Node *node, int val)
{
    if (node == nullptr)
    {
        Node *newNode = new Node(val);
        return newNode;
    }

    if (val < node->data)
    {
        node->left = insertHelper(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = insertHelper(node->right, val);
    }
    else
    {
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int bf = getBalancingFactor(node);

    if (bf > 1 && val < node->left->data) // left-left
    {
        return rightRotation(node);
    }
    if (bf < -1 && val > node->right->data) // right-right
    {
        return leftRotation(node);
    }
    if (bf > 1 && val > node->left->data) // left-right
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    if (bf < -1 && val < node->right->data) // right-left
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
};

bool AWL::search(int val)
{
    return searchHelper(root, val);
}
bool AWL::searchHelper(Node *node, int val)
{
    if (node == nullptr)
        return false;
    if (node->data == val)
        return true;
    else if (val < node->data)
        return searchHelper(node->left, val);
    return searchHelper(node->right, val);
}

int AWL::height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

int AWL::getBalancingFactor(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}
Node *AWL::leftRotation(Node *node)
{
    Node *rightNode = node->right;
    Node *rightNodeLeft = rightNode->left;

    rightNode->left = node;
    node->right = rightNodeLeft;

    rightNode->height = max(height(rightNode->left), height(rightNode->right));
    node->height = max(height(node->left), height(node->right));
    return rightNode;
};
Node *AWL::rightRotation(Node *node)
{
    Node *leftNode = node->left;
    Node *leftNodeRight = leftNode->right;

    leftNode->right = node;
    node->left = leftNodeRight;

    leftNode->height = max(height(leftNode->left), height(leftNode->right));
    node->height = max(height(node->left), height(node->right));
    return leftNode;
};
int main()
{
    AWL tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(5);
    cout << tree.search(10);
    return 0;
}