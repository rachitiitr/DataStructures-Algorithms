//The Coin Change Problem
//Given an Array of coins C, and money S, print number of ways to make a change for S
//Eg: A=[1,2] S=4 answer is {1,1,1,1}, {2,2}, {2,1,1} i.e 3 ways
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int A[N], n;
int vis[N][N], dp[N][N];

int ways(int pos, int S) {
	if(pos == n) return S == 0;
	int &ans = dp[pos][S];
  	if(vis[pos][S]) return ans; vis[pos][S] = 1, ans = 0;
	int times = 0;
	while(times*A[pos] <= S) ans += ways(pos+1, S-times*A[pos]), times++;
	return ans;
}

//Faster than ways function as it causes only two transitions
int fasterWays(int pos, int S) {
	if(pos == n) return S == 0;
 	 if(S < 0) return 0;
	int &ans = dp[pos][S];
 	 if(vis[pos][S]) return ans; vis[pos][S] = 1, ans = 0;
	ans = ways(pos, S-A[pos]) + ways(pos+1, S);
	return ans;
}

int main() {
	
	int i, S;
	cin >> n >> S;
	for(i=0; i<n; i++) cin >> A[i];	
	cout << fasterWays(0, S) << endl;
	return 0;
}
