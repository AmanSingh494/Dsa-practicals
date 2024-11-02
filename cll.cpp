#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int num) : data(num)
    {
        next = nullptr;
    }
};

class CircularLinkedList
{
    Node *head;
    int size;

public:
    CircularLinkedList()
    {
        head = nullptr;
        size = 0;
    };
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void deleteFromBeginning();
    void deleteFromEnd();
    Node *searchOnValue(int val);
    void display();
};
void CircularLinkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        newNode->next = newNode;
    }
    else
    {
        Node *lastNode = head;
        while (lastNode->next != head)
            lastNode = lastNode->next;
        lastNode->next = newNode;
        newNode->next = head;
    }
    head = newNode;
    size++;
    return;
}

void CircularLinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        Node *lastNode = head;
        while (lastNode->next != head)
            lastNode = lastNode->next;
        lastNode->next = newNode;
    }
    size++;
};

void CircularLinkedList::deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *secondLastNode = head;
    while (secondLastNode->next->next != head)
        secondLastNode = secondLastNode->next;
    Node* lastNode = secondLastNode -> next;
    secondLastNode->next = head;
    size--;
    delete lastNode;
};
void CircularLinkedList::deleteFromBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    Node *lastNode = head;
    while (lastNode->next != head)
        lastNode = lastNode->next;
    lastNode->next = head->next;
    head = head->next;
    size--;
    delete temp;
};

Node *CircularLinkedList::searchOnValue(int val)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return nullptr;
    }
    Node *current = head;
    do{
        if (current->data == val)
            return current;
        current = current->next;
    }while (current != head);
    
    cout << "Element not found" << endl;
    return nullptr;
};

void CircularLinkedList::display()
{
    Node *current = head;
    for (int i = 0; i < size; i++)
    {
        cout << current->data << ' ' << endl;
        current = current->next;
    }
}

int main()
{
    CircularLinkedList ll;
    ll.insertAtBeginning(12);
    ll.insertAtEnd(9);
    ll.insertAtBeginning(4);
    ll.insertAtEnd(2);
    ll.display();
    cout << "After deletion" << endl;
    ll.deleteFromEnd();
    ll.display();
    cout << ll.searchOnValue(5) << endl;
    return 0;
}