#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int [], int );

int main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	insertion_sort(arr, n);
	for (int f = 0; f < n; f++) cout << arr[f] << " ";

}


void insertion_sort(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--)
		{   arr[j + 1] = arr[j]; }
		arr[j + 1] = temp;
	}
}
