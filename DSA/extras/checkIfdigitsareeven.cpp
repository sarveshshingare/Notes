// // check if the digits of number are even

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {2, 4, 12, 934, 6767, 18231, 312713, 43, 5432, 43, 7, 8989};

//     int ans = 0;

//     for (int i : arr)
//     {
//         int count = 0;
//         int num = i;
//         while (num != 0)
//         {
//             num = num / 10;
//             count++;
//         }
//         if (count % 2 == 0)
//         {
//             ans++;
//         }
//     }
//     cout << "Number of even digits are :" << ans << endl;
//     return 0;
// }

// check if the digits of number are even

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 4, 12, 934, 6767, 18231, 312713, 43, 5432, 43, 7, 8989};

    int ans = 0;

    for (int i : arr)
    {
        if (i == 0)
        {
            continue;
        }
        int num_digits = floor(log10(i)) + 1;

        if (num_digits % 2 == 0)
        {
            ans++;
        }
    }
    cout << "Number of even digits are :" << ans << endl;
    return 0;
}