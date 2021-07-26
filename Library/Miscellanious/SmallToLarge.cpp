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
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
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
const int N = 3e5;
vi g[N];
int a[N];

//BEGIN
map<int, ll> cnt[N], val[N];
int id[N], col[N];
ll ans[N];
//http://codeforces.com/contest/600/problem/E
//Notice how ids of u and v swap due to &
void merge(int &u, int &v){
	if ((int)cnt[u].size() > (int)cnt[v].size()) swap(u, v);
	for (auto it: cnt[u]){
		int c = it.F; int occ = it.S;
		val[v][cnt[v][c]] -= c;
		cnt[v][c] += occ;
		val[v][cnt[v][c]] += c;
	}
}
void dfs(int u, int par){
	id[u] = u;
	cnt[u][col[u]] = 1;
	val[u][1] = col[u];
	for(int v: g[u]){
		if (v == par) continue;
		dfs(v, u);
		merge(id[v], id[u]);
	}
	ans[u] = val[id[u]].rbegin()->S;
}
//END
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j, u, v;
	cin>>n;
	fo(i, n) cin>>col[i+1];
	fo(i, n-1){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
    Fo(i, 1, n+1) cout<<ans[i]<<" ";
	return 0;
}

