#include <bits/stdc++.h>
using namespace std;

int getLength(char arr[])
{
    int count = 0;

    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
void reverseArr(char name[])
{
    int start = 0;
    int n = getLength(name);
    int end = n - 1;
    while (start <= end)
    {
        swap(name[start++], name[end--]);
    }
}
int main()
{
    char name[20];
    cin >> name;
    reverseArr(name);
    cout << "Reverse is : " << name << endl;

    return 0;
}