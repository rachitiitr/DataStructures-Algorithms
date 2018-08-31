//Given: An array A with all elements occuring twice except for x and y that occur once.
//To Do: Find the x and y in O(1) space and O(N) time
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int arr[N];

bool hasBitSet(int n, int x) {
	int tem = n & (1<<x);
	return tem!=0;
}

int main() {
	int n;
	cin >> n;
	
	int all = 0;
	int ans[2] = {0,0};
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
		all ^= arr[i];
	}
	
	//assert(all != 0); 
	int k = 0;
	while( hasBitSet(all, k) == 0 ) k++;
	
	//parition array into two sets: kth bit on v/s off
	for (int i=0; i<n; i++) {
		ans[hasBitSet(arr[i], k)] ^= arr[i];
	}
	
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}
