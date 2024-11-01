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

class SinglyLinkedList
{
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    };
    void insertAtBeginning(int data);
    void insertAtPosition(int data, int pos);
    void deleteFromBeginning();
    void deleteFromPosition(int pos);
    Node *searchOnValue(int val);
    void display();
};
void SinglyLinkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return;
}
void SinglyLinkedList::insertAtPosition(int data, int pos)
{
    Node *newNode = new Node(data);
    Node *nodeBefore = head;
    if (pos == 0)
        insertAtBeginning(data);
    for (int i = 0; i < pos - 1; i++)
    {
        if (nodeBefore->next == nullptr)
        {
            cout << "Given position is larger than the Linked list size" << endl;
            return;
        }
        nodeBefore = nodeBefore->next;
    }
    Node *nodeAfter = nodeBefore->next;
    nodeBefore->next = newNode;
    newNode->next = nodeAfter;
    return;
};

void SinglyLinkedList::deleteFromBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
};
void SinglyLinkedList::deleteFromPosition(int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (pos == 0)
        deleteFromBeginning();
    Node *beforePos = head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (beforePos->next == nullptr)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        beforePos = beforePos->next;
    }
    Node *RipNode = beforePos->next;
    if (RipNode == nullptr)
    {
        cout << "Position out of bounds" << endl;
        return;
    }
    beforePos->next = RipNode->next;
    delete RipNode;
};

Node *SinglyLinkedList::searchOnValue(int val)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return nullptr;
    }
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == val)
            return current;
        current = current->next;
    }
    cout << "Element not found" << endl;
    return nullptr;
};

void SinglyLinkedList::display()
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
    SinglyLinkedList ll;
    ll.insertAtBeginning(12);
    ll.insertAtBeginning(9);
    ll.insertAtBeginning(4);
    ll.insertAtBeginning(2);
    ll.insertAtPosition(1, 1);
    ll.display();
    cout << "After deletion" << endl;
    ll.deleteFromBeginning();
    ll.deleteFromPosition(3);
    ll.display();
    cout << ll.searchOnValue(1) << endl;
    return 0;
}