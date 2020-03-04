#include <bits/stdc++.h>
using namespace std;

void quick_sort(int[], int, int);
int partition(int[], int, int);

void quick_sort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}
int partition(int A[], int p, int r)
{
    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= A[r])
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int main()
{
    int A[50], n, i;
    cout << "How many elements?" << endl;
    cin >> n;
    cout << "\nEnter Array elements:" << endl;

    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    quick_sort(A, 0, n - 1);
    cout << "\nArray after sorting:";

    for (i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}