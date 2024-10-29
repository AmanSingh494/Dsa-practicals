#include <iostream>
using namespace std;

class Stack
{
    const int size;
    int *arr;
    int top;

public:
    Stack(int s) : size(s)
    {
        arr = new int[size];
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    int peek();
    int push(int num);
    int pop();
    int solvePreFix(string str);
    int solvePostFix(string str);
};

bool Stack::isEmpty()
{
    return top == -1;
}
bool Stack::isFull()
{
    return top == size - 1;
}
int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    return arr[top];
}
int Stack::push(int num)
{
    if (isFull())
    {
        cout << "Stack overflow" << endl;
    }
    arr[++top] = num;
    return arr[top];
}
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return arr[top--];
}
int Stack::solvePreFix(string str)
{
    int strSize = str.length();
    string exp = "";
    if (strSize > size)
    {
        cout << "Stack would overflow" << endl;
        return -1;
    }
    for (int i = strSize - 1; i >= 0; i--)
    {
        char c = str[i];
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int num1 = pop();
            int num2 = pop();
            int result;

            switch (c)
            {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0)
                {
                    result = num1 / num2;
                }
                else
                {
                    cout << "Division by zero error" << endl;
                    return -1;
                }
                break;
            default:
                cout << "Invalid operator" << endl;
                return -1;
            }

            push(result);
        }
        else if (isdigit(c))
        {
            int num = c - '0';
            push(num);
        }
        else if (c == ' ')
        {
            if (exp != "")
            {
                int num = stoi(exp);
                push(num);
                exp = "";
            }
        }
        else
        {
            cout << "Invalid character found: " << c << endl;
        }
    }
    return peek();
}
int Stack::solvePostFix(string str)
{
    int strSize = str.length();
    cout << strSize << endl;
    if (strSize > size)
    {
        cout << "Stack would overflow" << endl;
        return -1;
    }
    string exp = "";
    for (int i = 0; i < strSize; i++)
    {
        char c = str[i];
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int num2 = pop();
            int num1 = pop();
            int result;

            switch (c)
            {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0)
                {
                    result = num1 / num2;
                }
                else
                {
                    cout << "Division by zero error" << endl;
                    return -1;
                }
                break;
            default:
                cout << "Invalid operator" << endl;
                return -1;
            }
            push(result);
        }
        else if (isdigit(c))
        {
            exp += c;
            // int num = c - '0';
            // push(num);
        }
        else if (c == ' ')
        {
            if (exp != "")
            {

                int num = stoi(exp);
                push(num);
                exp = "";
            }
        }
        else
        {
            cout << "Invalid character found: " << c << endl;
        }
    }
    return peek();
}

int main()
{
    int size;
    cout << "Enter the size of the Stack" << endl;
    cin >> size;
    Stack st(size);
    string exp = "- * - 6 + 2 3 + 3 / 8 2 2";
    int result = st.solvePreFix(exp);
    cout << result << endl;
    return 0;
}