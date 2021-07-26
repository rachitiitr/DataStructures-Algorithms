#include <bits/stdc++.h>
using namespace std;
int vis[20][200]; 
long long dp[20][200];

//nos such that their # of digits <= X and digit sum = S
long long count(int dig, int S){
	
	if(dig == 0 or S < 0) return 0;
	if(S == 0) return 1;
	if(dig == 1) return S <= 9;
	
	long long &ans = dp[dig][S];
	if(vis[dig][S]) return ans;
	vis[dig][S] = 1;
	ans = 0;
	
	for(int i = 0; i <= 9; i++) ans += count(dig-1, S-i);
	
	return ans;
}

//nos < X with digit sum S
long long go(long long X, int S){
	string x = to_string(X);
	long long ans = 0;
	
	int remLen = x.size()-1;
	
	for(char c: x){
		int currDig = c-'0';
	
		//The first digit position where they differ is "i"
		for(int i = 0; i < currDig; i++){
			ans += count(remLen, S-i);
		}
		
		//Update the remaining lenght as well as the S
		//S is updated because currDig i.e x[i] is added to the prefix as
		//the next position where they differ will be i+1.
		remLen--;
		S -= currDig;
	}
	
	return ans;
	
}

int main() {
	long long L = 100, R = 1000, S = 13;
	cout << go(R+1, S)-go(L, S) << "<" << endl; 
	// cout << count(3, 10) << " " << count(1, 8) << endl;
	int i, ans = 0;
	auto digsum = [](int x){
		int s = 0;
		while(x) s+=x%10, x/=10;
		return s;
		
	};
	for(i=L; i<=R; i++) ans += digsum(i)==S;
	cout <<ans <<endl;
	
	return 0;
}
