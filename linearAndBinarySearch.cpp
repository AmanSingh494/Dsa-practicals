#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int *arr, int size, int num)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == num)
        {
            cout << "found the index" << endl;
            return mid;
        }
        else if (arr[mid] > num)
        {
            cout << "mid is bigger than num" << arr[mid] << " mid elem" << num << " num " << endl;
            end = mid - 1;
        }
        else
        {

            cout << "mid is smaller than num" << endl;
            start = mid + 1;
        }
        cout << "mid " << mid << " start " << start << " end " << end << endl;
    }

    return -1;
}

int main()
{
    int size;
    int num;
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
    cout << "Enter the number you want to find index of" << endl;
    cin >> num;
    int index = binarySearch(arr, size, num);
    cout << "The number is at index " << index << endl;
}