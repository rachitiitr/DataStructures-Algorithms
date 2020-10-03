// determines the kth smallest element of an input array using median of median method
#include <iostream>
#include <algorithm>
using namespace std;

int findMedian(int arr[], int n)
{
    sort(arr, arr + n); // Sort the array
    return arr[n / 2];  // Return middle element
}

void swapp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int f, int l, int r)
{
    for (int y = f; y <= l; y++) //to find index of r
        if (a[y] == r)
        {
            r = y;
            break;
        }
    swapp(a[l], a[r]);

    int pivot = a[l];
    int i = f - 1;

    for (int j = f; j < l; j++)
    {
        if (a[j] <= pivot)
            swapp(a[++i], a[j]);
    }
    swapp(a[++i], a[l]);
    return i;
}

//                  low    high
int Rselect(int a[], int l, int h, int k) // determines the kth smallest element of an input array
{
    int n = h - l + 1; //size of array

    if (k > 0 && k <= n)
    {
        int i, median[(n + 4) / 5]; //(n+4)/5 returns ceiling(n/5);

        for (i = 0; i < n / 5; i++)
        {
            median[i] = findMedian(a + l + i * 5, 5);
        }

        if (i * 5 < n)
        {
            median[i] = findMedian(a + l + i * 5, n % 5);
        }

        int medOfmed = (i == 0) ? median[i] : Rselect(median, 0, i, (i + 1) / 2);

        int p = partition(a, l, h, medOfmed);

        if (p - l == k - 1)
            return a[p];
        else if (p - l > k - 1)
            return Rselect(a, l, p - 1, k);
        else
            return Rselect(a, p + 1, h, k - (p - l + 1));
    }

    return INT32_MAX;
}

int main()
{
    int n, k;
    cout << "\nEnter No of elements in the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) //input
        cin >> arr[i];
    while (1)
    {
        cout << "\nEnter the order statistic : ";
        cin >> k;
        cout << '\n'
             << "The " << k << " order statistic is "
             << Rselect(arr, 0, n - 1, k);
    }
}