#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;

    // Total space : capacity
    // Total elements : size
    cout << "Capacity :" << v.capacity() << endl;
    cout << "Size :" << v.size() << endl;

    v.push_back(1);
    cout << "Capacity :" << v.capacity() << endl;
    cout << "Size :" << v.size() << endl;

    v.push_back(2);
    cout << "Capacity :" << v.capacity() << endl;
    cout << "Size :" << v.size() << endl;

    v.push_back(3);
    cout << "Capacity :" << v.capacity() << endl;
    cout << "Size :" << v.size() << endl;

    v.push_back(4);
    cout << "Capacity :" << v.capacity() << endl;
    cout << "Size :" << v.size() << endl;

    v.push_back(5);
    cout << "Capacity :" << v.capacity() << endl;
    cout << "Size :" << v.size() << endl;
    return 0;
    v.
}