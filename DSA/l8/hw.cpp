// 2) given two numbers a and b calculate the total number of set bits

#include <iostream>
using namespace std;
int calBit(int n)
{
    int count = 0;
    while (n != 0)
    {
        int bit = n & 1;

        // operation
        if (bit == 1)
        {
            count += 1;
        }

        n = n >> 1;
    }
    return count;
}
int main()
{
    int a, b;
    cin >> a >> b;

    cout << calBit(a) + calBit(b);

    return 0;
}
