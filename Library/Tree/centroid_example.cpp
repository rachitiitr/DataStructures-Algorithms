//http://codeforces.com/contest/716/problem/E
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
vpii g[N];
vi cur;
int part;
int a[N], gvis[N], lvl[N], stree[N];
ll up[N], down[N], sz[N];
int prime[N];
vl primes;
ll inv;

int mpow(int base, int exp);
ll PHI;
ll add(ll a, ll b);
ll mul(ll a, ll b);
void seive();
int phi(int n);
void dfs(int u, int par){
    //add u to current tree
    if (par == 0) cur.clear();
    cur.pb(u);
    lvl[u] = 1+lvl[par];
    sz[u] = 1;
    for(pii it: g[u]){
        int v = it.F;
        if (gvis[v] or v == par) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int centroid(int u, int par){

    for(auto it: g[u]){
        int v = it.F;
        if ( v == par or gvis[v]) continue;
        if (2*sz[v] > (int)cur.size()) return centroid(v, u);
    }
    return u;
}
void go(int u, int par, int cen){
    lvl[u] = 1+lvl[par];
    if(par == cen){
        stree[u] = part++;
    }
    else {
        stree[u] = stree[par];
    }
    for(auto it: g[u]){
        int v = it.F, w = it.S;
        if (v == par or gvis[v]) continue;
        down[v] = add( mul(10, down[u]), w);
        up[v] = add(up[u], mul(w, mpow(10, lvl[u])));
        go(v, u, cen);
    }
}
map<int, int> cnt, st[N];
ll solvefor(int cen){
    int i;
    //solve for centroid
    //init current parts of subtree
    part = 0;


    //make centroid as root
    //find levels

    //find up down values
    up[cen] = down[cen] = 0;
    stree[0] = N-1;
    go(cen, 0, cen);

    //precalculate the maps
    cnt.clear();
    fo(i, part) st[i].clear();

    //traverse only the current nodes in present tree
    for(int u: cur) cnt[up[u]]++, st[stree[u]][up[u]]++;


    //calculate ans
    ll ans = 0;
    for(int u: cur){
        if (u == cen){
            ans += cnt[0]-1;
        }
        else{
            ll val = mul((mod-(down[u]%mod))%mod, mpow(mpow(10, lvl[u]), PHI-1));
            ans += cnt[val] - st[stree[u]][val];
        }

    }

    return ans;
}
ll solve(int u){
    //dfs to calculate centroid
    dfs(u, 0);
    //find centroid of current tree
    int cen = centroid(u, 0);
    ll ans = solvefor(cen);
    //mark cen done in global visited
    //handles centroid decomposition later on
    gvis[cen] = 1;
    for(auto it: g[cen])
        if (!gvis[it.F])
            ans += solve(it.F);
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j, u, v, w;
	int t;
	cin>>n>>mod;
	seive();
	fo(i, n-1){
        cin>>u>>v>>w;
        u++, v++;
        g[u].pb({v, w});
        g[v].pb({u, w});
	}
	lvl[0] = -1;
	PHI = phi(mod);
	ll ans = solve(1);
	cout<<ans<<endl;

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

void seive(){
    ll i;
    Fo(i, 1, N) prime[i] = i;
    for(i=2; i*i < N; i++){
        if (prime[i] == i){
            primes.pb(i);
            for(ll j = 2*i; j < N; j += i)
                if (prime[j] == j)
                    prime[j] = i;
        }
    }
}
int phi(int n){
    int n1, n2;
    n2 = n; n1 = 1;
    int i = 0;
    while(i<(int)primes.size() and  primes[i]*primes[i] <= n){
        if (n % primes[i] == 0){
            while(n % primes[i] == 0) n /= primes[i];
            n2 /= primes[i];
            n1 *= primes[i]-1;
        }
        i++;
    }
    if (n>1){
        n2 /= n;
        n1 *= n-1;
    }
    return n1*n2;
}
ll add(ll a, ll b){
    a += b;
    return a%mod;
}
ll mul(ll a, ll b){
    a *= b;
    return a%mod;
}

