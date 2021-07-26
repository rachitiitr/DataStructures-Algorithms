#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);
//2d sparse table for max
//0 based index
//LGN = 1 + lg2(N)
//LGM = 1 + lg2(M)

const int N = 1030;
const int M = 1030;
const int LGN = 11;
const int LGM = 11;
vi g[N];
int a[N][M];
int dp[N][LGN][M][LGM];
const int MAXN = 2e6; //max(N, M)
int lg2[MAXN];
void pre(){
	//build lg2
	lg2[1] = 0;
	lg2[2] = 1;
	int val = 1, at = 4;
	int i;
	Fo(i, 3, MAXN){
		if (i == at){
			at *= 2;
			val++;
		}
		lg2[i] = val;
	}
}
void build(int n, int m){
	int ir, ic, jr, jc;
	//unit cells
	fo(ir, n)
	fo(ic, m) dp[0][ir][0][ic] = a[ir][ic];
	
	//fill 1-d sparse table for all rows
	fo(ir, n)
		Fo(jc, 1, LGM)
		for(ic = 0; ic + (1<<jc) <= m; ic++)
			dp[0][ir][jc][ic] = max(dp[0][ir][jc-1][ic], dp[0][ir][jc-1][ic+(1<<(jc-1))]);
	
	//fill 2-d sparse table
	Fo(jr, 1, LGN)
	for(ir = 0; ir + (1<<jr) <= n; ir++)
		Fo(jc, 0, LGN)
		for(ic = 0; ic + (1<<jc) <= n; ic++)
			dp[jr][ir][jc][ic] = max( dp[jr-1][ir][jc][ic], dp[jr-1][ir+(1<<(jr-1))][jc][ic] );
}
int query(int x1, int y1, int x2, int y2){
	int k1 = lg2[x2-x1+1];
	int k2 = lg2[y2-y1+1];
	int a1 = 0, a2 = 0;
	a1 = max( dp[k1][x1][k2][y1], dp[k1][x1][k2][y2-(1<<k2)+1] );
	a2 = max( dp[k1][x2-(1<<k1)+1][k2][y1], dp[k1][x2-(1<<k1)+1][k2][y2-(1<<k2)+1] );
	return max(a1, a2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,m;
	cin>>n>>m;
	fo(i,n)fo(j, m)cin>>a[i][j];
	build(n, m);
	cout<<query(1,2,2,3);
	
	
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
}#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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

//2d sparse table for max
//0 based index
//LGN = 1 + lg2(N)
//LGM = 1 + lg2(M)

const int N = 1030;
const int M = 1030;
const int LGN = 11;
const int LGM = 11;
vi g[N];
int a[N][M];
int dp[N][LGN][M][LGM];
const int MAXN = 2e6; //max(N, M)
int lg2[MAXN];
void pre(){
	//build lg2
	lg2[1] = 0;
	lg2[2] = 1;
	int val = 1, at = 4;
	int i;
	Fo(i, 3, MAXN){
		if (i == at){
			at *= 2;
			val++;
		}
		lg2[i] = val;
	}
}
void build(int n, int m){
	pre();
	int ir, ic, jr, jc;
	//unit cells
	fo(ir, n)
	fo(ic, m) dp[0][ir][0][ic] = a[ir][ic];
	
	//fill 1-d sparse table for all rows
	fo(ir, n)
		Fo(jc, 1, LGM)
		for(ic = 0; ic + (1<<jc) <= m; ic++)
			dp[0][ir][jc][ic] = max(dp[0][ir][jc-1][ic], dp[0][ir][jc-1][ic+(1<<(jc-1))]);
	
	//fill 2-d sparse table
	Fo(jr, 1, LGN)
	for(ir = 0; ir + (1<<jr) <= n; ir++)
		Fo(jc, 0, LGN)
		for(ic = 0; ic + (1<<jc) <= m; ic++)
			dp[jr][ir][jc][ic] = max( dp[jr-1][ir][jc][ic], dp[jr-1][ir+(1<<(jr-1))][jc][ic] );
}
int query(int x1, int y1, int x2, int y2){
	int k1 = lg2[x2-x1+1];
	int k2 = lg2[y2-y1+1];
	int a1 = 0, a2 = 0;
	a1 = max( dp[k1][x1][k2][y1], dp[k1][x1][k2][y2-(1<<k2)+1] );
	a2 = max( dp[k1][x2-(1<<k1)+1][k2][y1], dp[k1][x2-(1<<k1)+1][k2][y2-(1<<k2)+1] );
	return max(a1, a2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,m;
	cin>>n>>m;
	fo(i,n)fo(j, m)cin>>a[i][j];
	build(n, m);
	cout<<query(1,2,2,3);
	
	
	return 0;
} 

