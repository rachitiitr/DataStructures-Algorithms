#include<bits/stdc++.h>
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
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 300, M = N;
//=======================

vi g[N];
int a[N][M];

void solve() {
  int i, j, n, m;
  int x = 0;

  si(n);
  deb(n); // debug a variable easily 😉

  // fo demo
  {
    for(i=0; i < n; i++)
    for(j=0; j < n; j++)
      si(a[i][j]);

    // print sum
    int sum = 0;
    fo(i, n) fo(j, n) sum += a[i][j];
    deb(sum);
  }

  // Fo demo - works in both direction (0 to 100) as well as (100, 0)
  {
    fo(i, n) {
      Fo(j, n-1, -1) printf("%d ", a[i][j]); 
      printf("\n");
    }
  }


  // modulo
  {
    // (a * b) % mod    ==     ( (a%mod) * (b%mod) ) % mod
    int mpow_result = mpow(2, 1000);
    deb(mpow_result);
  }

  // vector, pair 
  {
	vpii ans = {{1, 1}, {-3, 9}, {10, 100}, {6, 36}};
	sortall(ans);

	for(pii x: ans) printf("[%d, %d]", x.F, x.S);
	printf("\n");
  }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    deb(t);
    
    while(t--) {
      solve();
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


