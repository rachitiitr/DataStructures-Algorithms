//http://codeforces.com/gym/100570/submission/21226425
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
int mod ;
const int N = 3e5;
vi g[N], cg[N];
vl stree[N], contri[N], wt[N];
vi cur;
int part;
int gvis[N], c_par[N];
const int LG = 20;
//LCA begins
//1 based index
int a[N], lvl[N], P[N][LG], sz[N];
ll D[N];
void predfs(int u, int par){
	if (!par)lvl[u] = D[u] = 0;
    P[u][0] = par;
    int pos = -1;
	for(int v:g[u]){
		int w = wt[u][++pos];
		if (v == par) continue;
		lvl[v] = 1+lvl[u];
		D[v] = w+D[u];
		predfs(v, u);
	}
}
void prelca(int n){
	int i, j;
	fo(i, LG) fo(j, n+1) P[j][i] = -1;
	lvl[0] = -1;
	predfs(1, 0);
	for(i=1; i<LG; i++){
        Fo(j, 1, n+1)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
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

ll dis(int u, int v){
	if (u == v) return 0;
    if (lvl[u] < lvl[v]) swap(u, v);
    int w = lca(u, v);
    return D[u] + D[v] - 2*D[w];
}
//lca ends
int tot = 0;
void dfs2(int u, int par){
	if (par == 0)tot = 0;
    sz[u] = 1;
    tot++;
    for(int v: g[u]){
        if (gvis[v] or v == par) continue;
        dfs2(v, u);
        sz[u] += sz[v];
    }
}
//centroid decomposition begins
int centroid(int u, int par){

    for(int v: g[u]){
        if ( v == par or gvis[v]) continue;
        if (2*sz[v] > tot) return centroid(v, u);
    }
    return u;
}
void decompose(int u, int par){
	dfs2(u, 0);
	int cen = centroid(u, 0);
	gvis[cen] = 1;
	if (par) c_par[cen] = par;
	for(int v: g[cen])
		if (!gvis[v]) decompose(v, cen);
}
//build centroid tree
void build_centroid_tree(int n){
	int i;
	Fo(i, 1, n+1) if (c_par[i]) cg[c_par[i]].pb(i);
}
void calc_root(int u, int root){
	stree[root].pb(dis(u, root));
	for(int v: cg[u]) 
		calc_root(v, root);
}
void calc_contri(int u, int root){
	int par = c_par[root];
	contri[root].pb(dis(u, par));
	for(int v: cg[u]) 
		calc_contri(v, root);
}
//traverse centroid tree
void traverse_centroid_tree(int u, int par){
	for(int v: cg[u]){
		if (v == par) continue;
		traverse_centroid_tree(v, u);
	}
	calc_root(u, u);
	if (!par) 
		return;
	calc_contri(u, u);
}
bool f(ll val, ll x){
	return val >= x;
}
int bin(vl &a, ll val, int lo, int hi){
	if (a.empty())return 0;
	if (val < 0)return 0;
	if (a[0] > val) return 0;
	if (lo == hi) return lo+1;
	if (lo+1 == hi){
		if(f(val, a[hi]))return hi+1;
		return lo+1;
	}
	int mid = (lo+hi)/2;
	if(f(val, a[mid])) return bin(a, val, mid, hi);
	else return bin(a, val, lo, mid-1);
}
//# nodes u | dis(u,v) <= l 
int query(int v, ll l){
	int ans = bin(stree[v], l, 0, (int)stree[v].size()-1);
	int u = v;
	int orig = v;
	v = c_par[v];
	while(v){
		ll y = dis(orig, v);
		ans += bin(stree[v], l-y, 0, (int)stree[v].size()-1);
		ans -= bin(contri[u], l-y, 0, (int)contri[u].size()-1);
		u = v;
		v = c_par[v];
	}
	return ans;
}

//centroid decomposition ends
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i,n,k,j, u, v, w, q;
	int t;
	cin>>n>>q;
	fo(i, n-1){
        cin>>u>>v>>w;
        g[u].pb(v);
        g[v].pb(u);
        wt[v].pb(w);
        wt[u].pb(w);
	}
	prelca(n);
	decompose(1, 0);
	build_centroid_tree(n);
	Fo(i, 1, n+1) 
		if (!c_par[i])
			traverse_centroid_tree(i, 0);
	Fo(i, 1, n+1) sortall(contri[i]);
	Fo(i, 1, n+1) sortall(stree[i]);
	while(q--){
		cin>>v>>w;
		cout<<query(v, w)<<endl;
	}
	return 0;
}

int mpow(int base, int exp) {
base %= mod;
int result = 1;
while (exp > 0) {
if (exp & 1) result = ((ll)result * base) % mod;
base = ((ll)base * base) % mod;
exp >>= 1;
}
return result;
}
