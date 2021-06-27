#include <iostream>

using namespace std;

void Insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = key;       
    }
}

void BucketSort(int a[], int n, int k)
{
    int max = 0;
    for (int i = 0; i < n; i++)
        if (max < a[i])
            max = a[i];
    max++;

    int bucket[k][n];
    int size[k] = {0};

    for (int i = 0; i < n; i++)
    {
        int index = k * a[i] / max;
        bucket[index][size[index]] = a[i];
        size[index]++;
    }
    for (int i = 0; i < k; i++)
    {
        Insertionsort(bucket[i], size[i]);
    }
    for (int i = 0, j = 0; j < k; j++)
    {
        for (int l = 0; l < size[j]; l++)
            a[i++] = bucket[j][l];
    }
}

int main()
{
    int n;
    cout << "\nEnter No of elements in the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) //input
        cin >> arr[i];
    BucketSort(arr, n, 5);
    cout << "\nSorted Array : ";
    for (int i = 0; i < n; i++) //output
        cout << arr[i] << " ";
}