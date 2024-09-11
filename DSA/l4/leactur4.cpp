// fibonacci series
// 0 1 1 2 3 5 8 13 21
// #include <iostream>
// using namespace std;

// int main()
// {
//     int a = 0;
//     int b = 1;
//     int n;
//     cin >> n;
//     cout << a << " " << b << " ";
//     for (int i = 0; i < n; i++)
//     {
//         int nextNum = a + b;
//         cout << nextNum << " ";
//         a = b;
//         b = nextNum;
//     }

//     return 0;
// }

// prime or not

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool isPrime = true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            // cout << "Not a prime" << endl;
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << "Prime number";
    }
    else
    {
        cout << "Not a Prime number";
    }
    return 0;
}