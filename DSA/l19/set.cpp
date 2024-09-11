#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s;

    s.insert(5);
    s.insert(45);
    s.insert(55);
    s.insert(15);
    s.insert(35);
    s.insert(35);
    s.insert(35);
    

    for (
        int i : s)
    {
        cout << i << endl;
    }
    return 0;
}