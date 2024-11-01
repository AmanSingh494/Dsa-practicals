#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int num) : data(num)
    {
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    };
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void deleteFromBeginning();
    void deleteFromEnd();
    void display();
};
void DoublyLinkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    if (head == nullptr)
    {
        tail = newNode;
    }
    else
        head->prev = newNode;
    head = newNode;
    return;
}
void DoublyLinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);
    newNode->prev = tail;
    if (tail == nullptr)
    {
        head = newNode;
    }
    else
        tail->next = newNode;
    tail = newNode;
    return;
}

void DoublyLinkedList::deleteFromBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == nullptr)
        tail = nullptr;
    else
        head->prev = nullptr;
    delete temp;
};
void DoublyLinkedList::deleteFromEnd()
{
    if (tail == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    if (tail == nullptr)
        head = nullptr;
    else
        tail->next = nullptr;
    delete temp;
};

void DoublyLinkedList::display()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << ' ' << endl;
        current = current->next;
    }
}

int main()
{
    DoublyLinkedList ll;
    ll.insertAtBeginning(12);
    ll.insertAtBeginning(9);
    ll.insertAtEnd(4);
    ll.insertAtEnd(2);
    ll.display();
    cout << "After deletion" << endl;
    ll.deleteFromBeginning();
    ll.deleteFromEnd();
    ll.display();
    return 0;
}