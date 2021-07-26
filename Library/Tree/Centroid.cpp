#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 5e5;
vi g[N];
int a[N], par[N], ans[N], sz[N];
int cen, n;
void ipgraph(int n, int m);
void dfs(int u, int p){
	sz[u] = 1;
	for( int v: g[u]){
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void dfs2(int u, int p){
	sz[u] = 1;
	if ( p == cen ) par[u] = u;
	else par[u] = par[p];
	for( int v: g[u]){
		if (v == p) continue;
		dfs2(v, u);
		sz[u] += sz[v];
	}
}
void go(int u, int p){
	int hai = 1;
	for(int v: g[u]){
		if ( v == p ) continue;
		if ( sz[v] > n/2 ) hai = 0;
		go(v, u);
	}
	int other = n - sz[u];
	if ( other > n/2 ) hai = 0;
	if (hai) cen = u;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, m;
	cin >> n ;
	m = n  - 1;
	ipgraph(n, n-1);
	clr(sz);
	par[0] = 0;
	dfs(1, 0);
	go(1, 0);
	dfs2(cen, 0);
	int F, S, idx;
	F = S = idx = -1;
	Fo(i, 1, n+1) {
		if (par[i] == i) {
			if (sz[i] >= F){
				idx = i;
				S = F;
				F = sz[i];
			}
			else if (sz[i] > S) S = sz[i];
		}
	}
	Fo(i, 1, n+1){
		if ( i == cen ) {
			ans[i] = 1;
			continue;
		}
		int rep = par[i];
		int mx, other;
		if ( rep == idx ){
			mx = max(S, F - sz[i]);
		}
		else mx = F;
		other = n - sz[i] - mx;
		ans[i] = other <= n/2;
	}
	Fo(i, 1, n+1) cout<<ans[i]<<" ";

	return 0;
}


void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		u++, v++;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}
