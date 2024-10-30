#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    const int capacity;
    int size;
    int *arr;

public:
    Queue(int s) : capacity(s)
    {
        front = 0;
        rear = -1;
        arr = new int[capacity];
    }
    bool isEmpty();
    bool isFull();
    int enqueue(int num);
    int dequeue();
    int peek();
};

bool Queue::isEmpty()
{
    if (size == 0)
    {
        cout << "Queue is empty";
        return true;
    }
    return false;
}
bool Queue::isFull()
{
    if (size == capacity)
    {
        cout << "Queue is full";
        return true;
    }
    return false;
}
int Queue::enqueue(int num)
{
    if (isFull())
        return -1;
    rear = (rear + 1) % capacity;
    arr[rear] = num;
    size++;
};
int Queue::dequeue()
{
    if (isEmpty())
        return -1;
    int elem = arr[front];
    front = (front + 1) % capacity;
    size--;
};
int Queue::peek()
{
    if (isEmpty())
        return -1;
        cout << "front " << front << endl;
    return arr[front];
};

int main()
{
    int size;
    cout << "Enter the size of the Stack" << endl;
    cin >> size;
    Queue q(size);
    q.enqueue(10);
    q.enqueue(21);
    q.enqueue(14);
    q.enqueue(9);
    q.dequeue();
    cout << "The front element is " << q.peek()<<endl;
    return 0;
}