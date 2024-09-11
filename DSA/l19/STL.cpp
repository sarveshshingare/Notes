#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 4> arr = {1, 2, 3, 4};

    // 1. size
    int size = arr.size();

    // 2. traversing

    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    // 3. specific index

    cout << "Element at 2nd index :" << arr.at(2) << endl;

    // 4. check if empty

    cout << "Is empty or not :" << arr.empty() << endl;

    // first and last element

    cout << "first and last element is :" << arr.front() << " & " << arr.back() << endl;

    return 0;
}