#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d",x)
#define pl(x)	printf("%lld",x)
#define ps(s)	printf("%s",s)
#define pnl()   printf("\n")
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
const int N = 130, M = N;
//=======================

vi g[N];
int a[N][N];
int n;
bool f(tuple<int, int, int> &l, tuple<int, int, int> &r) {
    if(get<1>(l) != get<1>(r)) return get<1>(l) < get<1>(r);
    return get<0>(l) < get<0>(r);
}

int main() {
    // ios_base::sync_with_stdio(0);
    int t, i, j, k, p, q, r, x, y, u, v, m, tt, idx;
    vector<char> rep = {'C', 'J'};
    si(t);
    fo(tt, t) {
        si(n);
        int imposs(0);
        vector<char> ans(n, -1);
        vector<tuple<int, int, int>> act;
        fo(i, n) {
            cin >> x >> y;
            act.push_back({x, y, i});
        }
        
        sort(act.begin(), act.end(), f);
        int to = 0;
        int other = 1;
        vector<int> mx = {-1, -1};
        for(auto cur: act) {
            tie(x, y, idx) = cur;
            if(mx[to] <= x) {
                ans[idx] = to;
                mx[to] = y;
            }
            else if(mx[other] <= x) {
                ans[idx] = other;
                mx[other] = y;
            }
            else {
                imposs = 1;
            }
        }

        ps("Case #"); pi(tt+1); ps(": ");
        if(imposs) printf("IMPOSSIBLE");
        else for(int x: ans) printf("%c", rep[x]);
        pnl();
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

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}


