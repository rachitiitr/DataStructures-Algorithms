#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
  #include "logger.h"
#else
  #define deb(...)
  #define deb(...)
#endif
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
int mpow(int base, int exp); 
//=======================
const int MOD = 1'000'000'007;
const int N = 2003, M = N;
vector<int> g[N];
int a[N];

void solve() {
    
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

int mpow(int base, int exp) {
  base %= MOD;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % MOD;
    base = ((ll)base * base) % MOD;
    exp >>= 1;
  }
  return result;
}