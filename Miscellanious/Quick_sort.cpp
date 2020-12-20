#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int h)
{
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}
void quick_sort(int arr[],int l,int h) 
{
    if(l<h)
    {
        int pi=partition(arr,l,h);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,h);
    }
}
void display(int arr[],int n)
{
    cout<<"Array elements in sorted order\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n+1];
    cout<<"Enter the elements of array\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quick_sort(arr,0,n);
    display(arr,n);
    return 0;
}
