#include <bits/stdc++.h>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
const int rtn = 600;
int local[N], bkt[N];
int mat[rtn+1][rtn+1];
int dp[rtn+1][rtn+1], en[rtn+1];
unordered_map<int, int> cnt[rtn+1];

void compute(int b){
	cnt[b].clear();
	int i;
	dp[b][0] = mat[b][0];
	Fo(i, 1, en[b]+1){
		dp[b][i] = mat[b][i] ^ dp[b][i-1];
	}
	Fo(i, 0, en[b]+1) cnt[b][dp[b][i]]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j, type, x, _i = 0, q;
	int b = -1;
	
	si(n); si(q);
	fo(i, n) {
		si(a[i]);
		if(i%rtn == 0){
			if(b>=0) compute(b);
			b++, _i = 0;
		}
		
		bkt[i] = b;
		local[i] = _i;
		en[b] = _i;
		mat[b][_i] = a[i];
		_i++;
	}
	compute(b);
	
	while(q--){
		si(type);
		si(i);
		si(x);
		i--;
		if(type == 1){
			//update a[i] = x;
			b = bkt[i];
			_i = local[i];
			mat[b][_i] = x;
			compute(b);
		}
		else{
			//query prefixes with xor = x, and end before i
			int b = bkt[i];
			int ans = 0, ptr = 0, pre = 0;
			while(bkt[ptr] < b){
				int cur_bkt = bkt[ptr];
				int need = x ^ pre;
				ans += cnt[cur_bkt][need];
				pre ^= dp[cur_bkt][en[cur_bkt]];
				ptr += rtn;
			}
			Fo(j, 0, local[i]+1){
				pre ^= mat[b][j];
				if(pre == x) ans++;
			}
			printf("%d\n", ans);
		}
	}

	return 0;
} 
