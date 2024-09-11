#include <iostream>
using namespace std;

// nCr= n!
//  (r!*(n-r)!)
int fact(int a)
{
    int ans = 1;
    for (int i = 1; i <= a; i++)
    {
        ans = ans * i;
    }
    return ans;
}

int nCr(int n, int r)
{
    int num = fact(n);

    int den = fact(r) * fact(n - r);
    int ans = num / den;
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;

    cout << "factorial is :" << nCr(a, b);

    return 0;
}