//http://agc002.contest.atcoder.jp/tasks/agc002_d
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
const ll N = 3e5;
vi g[N];
pii E[N];
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);
struct node{
	int i, a, b, z;
};
int T, n, m, ans[N], rep[N], sz[N];
vector<node> Q;
int get(int x){
	if (x == rep[x]) return x;
	return rep[x] = get(rep[x]);
}
void merge(int x, int y){
	x = get(x);
	y = get(y);
	if (x == y) return;
	if (sz[x] < sz[y]) rep[x] = y, sz[y] += sz[x];
	else if (sz[x] > sz[y]) rep[y] = x, sz[x] += sz[y];
	else rep[x] = y, sz[y]+=sz[x];
}
void init(){
	int i;
	T = 0;
	Fo(i, 1, n+1) rep[i] = i, sz[i] = 1;
}
int go(int x, int y){
	x = get(x), y = get(y);
	if (x == y) return sz[x];
	return sz[x] + sz[y];
}
void solve(){
	queue< tuple<int, int, vector<node>> > q;
	vector<node> query;
	q.push(make_tuple(0, m, Q));
	int L, R, i;
	while(!q.empty()){
		
		tie(L, R, query) = q.front(); q.pop();
		if (L+1 == R){
			for(auto it: query)
				ans[it.i] = R;
			continue;
		}
		int mid = (L+R)/2;
		vector<node> left, right; left.clear(); right.clear();
		//execute till mid
		if (T > mid){
			init();
			T = 0;
		}
		Fo(i, T+1, mid+1){
			merge(E[i].F, E[i].S);
		}
		T = mid;
		//update range for each query
		for(auto it: query){
			if (go(it.a, it.b) >= it.z) left.pb(it);
			else right.pb(it);
		}
		
		q.push(make_tuple(L, mid, left));
		q.push(make_tuple(mid, R, right));
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,k,j,u,v,w;
	cin>>n>>m;
	fo(i, m){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
		E[i+1] = {u, v};
	}
	int q;
	cin>>q;
	Fo(i, 1, q+1){
		cin>>u>>v>>w;
		Q.pb({i, u, v, w});
	}
	init();
	solve();
        Fo(i, 1, q+1)
		cout<<ans[i]<<endl;
	
	return 0;
} 
