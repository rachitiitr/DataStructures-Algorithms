#include <bits/stdc++.h>
//http://codeforces.com/contest/794/submission/27087664
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
const ll mod = 1000000007*1LL*1000000007;
const int N = 3e5 + 3, M = N;
//=======================

set<int> g[N];
int sz[N], par[N];
int rep(int x){
	if(x == par[x]) return x;
	return par[x] = rep(par[x]);
}
void unite(int x, int y){
	x = rep(x);	
	y = rep(y);	
	if(x==y)return;
	if(sz[x]<sz[y]);
	else swap(x, y);
	par[x] = y;
	if(sz[x] == sz[y])
		sz[y]++;
}

ll h[N], val[N];
ll r(){
	return rand()*32000+rand();	
}
map<int,int> taken;
set<ll> allvals;
map<ll, vi> com;
int ass[N], T;
void go(int u){
	
	int cur = ass[u];
	for(int v: g[u]){
		if(ass[v]){
			if(abs(ass[v]-ass[u])>1){
				cout <<"NO\n";
				exit(0);
			}
		}
		else{
			if(!taken[cur+1])
			ass[v] = cur+1;
			else if(!taken[cur-1])
			ass[v] = cur-1;
			else{
				cout <<"NO\n";
				exit(0);
			}
			T = max(T, ass[v]+2);
			taken[ass[v]] = 1;
			go(v);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j, u, v, x, y, a, b, c, m;
	cin >> n >> m;
	srand(1234);
	Fo(i, 1, n+1) h[i] = (r()*r()+r())%mod;
	Fo(i, 1, n+1){
		par[i] = i;
		sz[i] = 0;
	}
	fo(i, m) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	Fo(i, 1, n+1){
		val[i] = h[i];
		for(int x: g[i]){
			val[i] = (val[i] + h[x])%mod;
		}
		allvals.insert(val[i]);
		com[val[i]].pb(i);
	}
	for(ll c: allvals){
		int x = com[c].size();
		if(x>1){
			u = com[c][0];
			for(int v: com[c])
				unite(u, v);
		}
	}
	Fo(i, 1, n+1){
		set<int> allnew; allnew.clear();
		for(int v: g[i]){
			allnew.insert(rep(v));
		}
		g[i].clear();
		for(int v: allnew) {
			if(v != i)
				g[i].insert(v);
		}
		int nsz = g[i].size();
		if(nsz > 2 and i == rep(i)){
			cout <<"NO\n";
			return 0;
		}
	}
	T = n+2; //take it bigger enough to avoid negative values
	Fo(i, 1, n+1){
		u = rep(i);
		if(u != i) continue;
		if(!ass[i]) ass[i] = T,taken[T] = 1, go(i);
	}
	cout<<"YES\n";
	Fo(i, 1, n+1){
		cout << ass[rep(i)] << " ";
	}
	return 0;
} 
