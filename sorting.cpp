#include <iostream>
using namespace std;

// Bubble sort
class BubbleSort
{
    const int size;
    int *arr;

public:
    BubbleSort(int x, int *array) : arr(array), size(x)
    {
    }
    void sort();
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
            cout << endl;
        }
    }
};
void BubbleSort::sort()
{
    cout << "Inside bubble sort" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection sort
class SelectionSort
{
    const int size;
    int *arr;

public:
    SelectionSort(int x, int *array) : arr(array), size(x)
    {
    }
    void sort();
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
            cout << endl;
        }
    }
};
void SelectionSort::sort()
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Selection sort
class InsertionSort
{
    const int size;
    int *arr;

public:
    InsertionSort(int x, int *array) : arr(array), size(x)
    {
    }
    void sort();
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
            cout << endl;
        }
    }
};
void InsertionSort::sort()
{
    for (int i = 1; i < size; i++)
    {
        int elem = arr[i];
        int index = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > elem)
            {
                arr[j + 1] = arr[j];
                index = j;
            }
            else if (arr[j] <= elem)
            {
                break;
            }
        }
        arr[index] = elem;
    }
}

// Merge sort
class MergeSort
{
    const int size;
    int *arr;

public:
    MergeSort(int x, int *array) : arr(array), size(x)
    {
    }
    void sort(int l, int h);
    void merge(int l, int m, int h);
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
            cout << endl;
        }
    }
};
void MergeSort::merge(int l, int m, int h)
{
    int temp[h - l + 1];
    int left = l;
    int right = m + 1;
    int current = 0;
    while (left <= m && right <= h)
    {
        if (arr[left] <= arr[right])
        {
            temp[current] = arr[left];
            left++;
        }
        else
        {
            temp[current] = arr[right];
            right++;
        }
        current++;
    }
    while (left <= m)
    {
        temp[current] = arr[left];
        left++;
        current++;
    }
    while (right <= h)
    {
        temp[current] = arr[right];
        right++;
        current++;
    }
    // updating the original array
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i - l];
    }
}
void MergeSort::sort(int l, int h)
{
    if (l >= h)
        return;
    int m = (l + (h - 1)) / 2;
    sort(l, m);
    sort(m + 1, h);
    merge(l, m, h);
}

int main()
{
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the array" << endl;
    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;
        arr[i] = n;
    }
    MergeSort myArr(size, arr);
    myArr.sort(0, size - 1);
    myArr.display();
    return 0;
}