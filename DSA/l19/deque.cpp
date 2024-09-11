#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> doubly;
    doubly.push_back(10);
    doubly.push_front(5);
    doubly.push_front(5);
    doubly.push_front(5);
    doubly.push_front(5);
    cout << doubly.size() << endl;

    return 0;

    deque<int>::iterator it;
    it = doubly.end();
    doubly.erase(it);

    for (int i : doubly)
    {
        cout << i << endl;
    }
}