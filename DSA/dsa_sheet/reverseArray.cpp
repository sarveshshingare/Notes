#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int arr[] = {10, 90, 21313, 32, 12, 53, 67, 5435};
    int size = 8;
    reverseArray(arr, size);
    printArray(arr, size);
    return 0;
}