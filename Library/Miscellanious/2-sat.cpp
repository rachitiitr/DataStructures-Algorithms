#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
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
//http://codeforces.com/gym/100570/problem/D
//"2-sat" and "small to large" merging 
//N must be atleast twice the value of nodes
const int N = 5e5;

int a[N], par[N], n, q;
map<ll, int> mep;
vi comp[N];

void add(ll &x){
	if (mep.find(x) == mep.end())
		mep[x] = mep.size();
	x = mep[x];
}

void out(){
	while(q++ < n) printf("No\n");
	exit(0);
}
void merge(int u, int v){
	u = par[u];
	v = par[v];
    	if (u == v) return;
	if ((int)comp[u].size() > (int)comp[v].size()) swap(u, v);
	//v is bada
	vi &r = comp[v];
	// each time we merge two components
	// size increases atleast by 2 * chote set ka size
	//each node can move at most log2(n) times
	// n * log(n) complexity mei merge hojayega
	for(int x: comp[u]){
		if (par[x^1] == v) out();
		r.pb(x);
		par[x] = v;
	}
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int i,k,j;
	si(n);
	ll x, y, a, b;
	fo(i, N) par[i] = i, comp[i].clear(), comp[i].pb(i);
	fo(i, n){
		q = i;
		sl(x);	sl(y);	sl(a);	sl(b);
        	y = -y;
		add(x); add(y);
		x *= 2;
		y *= 2;
		if (a == b){
			merge(x, y);
			merge(x^1, y^1);
		}
		else{
			merge(x, y^1);
			merge(x^1, y);
		}
		printf("Yes\n");		
	}
   
	return 0;
} 

