#include <iostream>
using namespace std;

// Divide and conquor algorithm

struct Pair
{
    int min;
    int max;
};

Pair getminmax(int arr[], int start, int end)
{
    Pair minmax, minMaxleft, minMaxright;
    int mid;
    // one element
    if (start == end)
    {
        minmax.max = arr[start];
        minmax.min = arr[end];
        return minmax;
    }

    // two element
    if (start == end - 1)
    {
        // comapre
        if (arr[start] > arr[end])
        {
            minmax.max = arr[start];
            minmax.min = arr[end];
        }
        else
        {
            // arr[start]<arr[end]
            minmax.max = arr[end];
            minmax.min = arr[start];
        }
        return minmax;
    }

    // more than 2 elements
    mid = start + (end - start) / 2;
    minMaxleft = getminmax(arr, start, mid);
    minMaxright = getminmax(arr, mid + 1, end);

    // find min
    if (minMaxleft.min < minMaxright.min)
    {
        minmax.min = minMaxleft.min;
    }
    else
    {
        minmax.min = minMaxright.min;
    }
    // find max
    if (minMaxleft.max > minMaxright.max)
    {
        minmax.max = minMaxleft.max;
    }
    else
    {
        minmax.max = minMaxright.max;
    }

    return minmax;
}

int main()
{
    int arr[] = {10, 90, 21313, 32, 12, 53, 67, 5435};

    Pair minmax = getminmax(arr, 0, 7);

    cout << "min is :" << minmax.min << endl;
    cout << "mmax is :" << minmax.max << endl;

    return 0;
}