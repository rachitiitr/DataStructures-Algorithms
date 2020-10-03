#include <iostream>
using namespace std;

void Countsort(int a[], int n)
{
    int k = 0; //max element
    for (int i = 0; i < n; i++)
        if (a[i] > k)
            k = a[i];
    int count[k+1] = {0}, temp[n];
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    for (int i = 1; i <= k; i++)
        count[i] = count[i - 1] + count[i];
    for (int i = n - 1, j = k - 1; i >= 0; i--)
    {
        temp[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = temp[i];
}

int main()
{
    int n;
    cout << "\nEnter No of elements in the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)//input
        cin >> arr[i];
    Countsort(arr, n);
    cout << "\nSorted Array : ";
    for (int i = 0; i < n; i++)//output
        cout << arr[i] << " ";
}
