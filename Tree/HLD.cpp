#include <bits/stdc++.h>
// http://www.spoj.com/problems/QTREE/
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
struct node{int v, w, i;};
vector<node> g[N];
int a[N], pos[N], arr[N];
int sz[N], lvl[N], rep[N];
int P[N][20], n;
int chainNo, ptr;
int chainOf[N], chainHead[N];
int tree[4*N];

void dfs(int u, int par){
    sz[u] = 1;
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
	for(node to:g[u]){
		int v = to.v;
		if (v == par) continue;
		rep[to.i] = v;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

int lca(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);
    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;
    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }
    if (u == v) return u;
    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }
    return P[u][0];
}
void init(){
	int i, j;
	Fo(i, 0, n+1) g[i].clear();
	ptr = 0, chainNo = 1;
	sz[0] = arr[0] = 0;
	lvl[0] = -1;
	Fo(i, 0, n+1) {
		chainHead[i] = -1;
		pos[i] = arr[i] = 0;
		Fo(j, 0, 20) P[i][j] = -1;
	}
}
int range_query(int rt, int lo, int hi, int x, int y){
	if(lo == x and hi == y) return tree[rt];
	int l = 2*rt, r = l+1, mid = (lo+hi)>>1;
	if(y <= mid) return range_query(l, lo, mid, x, y);
	if(x > mid) return range_query(r, mid+1, hi, x, y);
	return max(range_query(l, lo, mid, x, mid), range_query(r, mid+1, hi, mid+1, y));
}
int query_up(int u, int v){
	if(u == v) return 0;
	if(lvl[u] < lvl[v]) swap(u, v);
	int uchain, vchain = chainOf[v];
	int ans = 0;
	while(1){
		uchain = chainOf[u];
		if(uchain == vchain){
			if(u == v) return ans;
			ans = max(ans, range_query(1, 0, ptr, pos[v]+1, pos[u]));
			return ans;
		}
		ans = max(ans, range_query(1, 0, ptr, pos[chainHead[uchain]], pos[u]));
		u = chainHead[uchain];
		u = P[u][0];
	}
	return ans;
}
void hld(int u, int cost, int par){
	if(chainHead[chainNo] == -1) 
		chainHead[chainNo] = u;
	chainOf[u] = chainNo;
	pos[u] = ++ptr;
	arr[ptr] = cost;
	int sc = 0, w;
	for(node to: g[u]){
		int v = to.v;
		if(v == par) continue;
		if(sz[sc] < sz[v])sc = v, w = to.w;
 	}
	if(sc) hld(sc, w, u);
	for(node to: g[u]){
		int v = to.v;
		if(v == par or v == sc) continue;
		chainNo++;
		hld(v, to.w, u);
 	}
}
void build(int rt, int lo, int hi){
	if(lo == hi){
		tree[rt] = arr[lo];
		return;
	}
	int l = 2*rt, r = l+1, mid = (lo+hi)>>1;
	build(l, lo, mid);
	build(r, mid+1, hi);
	tree[rt] = max(tree[l], tree[r]);
}
void update(int rt, int lo, int hi, int pos, int val){
	if(lo == hi){
		tree[rt] = val;
		return;
	}
	int l = 2*rt, r = l+1, mid = (lo+hi)>>1;
	if(pos<=mid) update(l, lo, mid, pos, val);
	else update(r, 1+mid, hi, pos, val);
	tree[rt] = max(tree[l], tree[r]);
}

int query(int u, int v){
	int w = lca(u, v);
	int ans = max(query_up(u, w), query_up(v, w));
	return ans;
}
void change(int i, int val){
	int u = rep[i];
	update(1, 0, ptr, pos[u], val);
}
void compute(){
	int i, j;
	dfs(1, 0);
	for(i=1; i<20; i++){
        Fo(j, 1, n+1)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
	}
	hld(1, 0, 0);
	//make segment tree now
	assert(ptr == n);
	build(1, 0, ptr);
}
void solve(){
	int i;
	si(n);
	init();
	int u, v, w;
	char s[10];
	fo(i, n-1){
		si(u);
		si(v);
		si(w);
		g[u].pb({v, w, i+1});
		g[v].pb({u, w, i+1});
	}
	compute();
	ss(s);
	while(1){
		if(s[0] == 'D') break;
		si(u); si(v);
		if(s[0] == 'C'){
			change(u, v);
		}
		else{
			pi(query(u, v));
		}
		ss(s);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,k,j;
	int t;
	si(t);
	while(t--) solve();
	return 0;
} 
