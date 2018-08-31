//Given: An array A with all elements occuring twice except for x that occur once.
//To Do: Find the element x O(1) space and O(N) time
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int arr[N];
 
int main() {
	int n;
	cin >> n;
 
	int all = 0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		all ^= arr[i];
	}
 
	cout << all << endl;
 
	return 0;
}
