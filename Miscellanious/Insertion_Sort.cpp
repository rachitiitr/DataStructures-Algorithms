#include <bits/stdc++.h> 
using namespace std; 

void display(int arr[], int n){  
    int i;  
    for(i = 0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
}

void insertion_sort(int arr[], int n){  
    int i, j, key;  
    for (i = 1; i<n; i++){  
        key = arr[i];  
        j = i-1;  
        while (j>=0 && arr[j]>key){  
            arr[j+1] = arr[j];  
            j = j-1;  
        }
        arr[j+1] = key;  
    }  
    display(arr, n); 
}
  
int main(){  
    int arr[] = { 32, 17, 8, 19, 54, 6, 63, 21, 12 };  
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    return 0;
}