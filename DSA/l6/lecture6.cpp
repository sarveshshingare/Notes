// #include <iostream>
// #include <math.h>
// using namespace std;
// // binary to decimal
// // 5=> 101
// int main()
// {
//     int n;
//     cin >> n;
//     cout << n << endl;
//     float ans = 0;
//     int i = 0;
//     while (n != 0)
//     {
//         int bit = n & 1; // gives the bit
//         ans = (bit * pow(10, i)) + ans;
//         n = n >> 1;
//         i++;
//     }
//     cout << "Binary is :" << ans << endl;
//     return 0;
// }

// NOT POSSIBLE LIKE THIS
// decimal to binary of a negative number
// eg -6 => 11111010

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n; // consider w/o -ve sign
    cin >> n;

    float binaryNum = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        // cout << bit << endl;

        if (bit == 1)
        {
            bit = 0;
        }
        else
        {
            bit = 1;
        }

        binaryNum = (bit * pow(10, i) + binaryNum);
        n = n >> 1;
        i++;
    }
    cout << binaryNum;
    // // ones comp
    // // 0000...00110
    // while(binaryNum!=0){

    // }
    return 0;
}