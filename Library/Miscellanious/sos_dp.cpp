#include <bits/stdc++.h>
// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/special-pairs-7/description/
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
const int mod = 1000000007;
const int N = 1LL<<20, M = N;
//=======================

vi g[N];
int a[N];
const int B = 20;
ll dp[N][B];
int cnt[N];
void sosdp(){
	int i, j;
	fo(i, N){
		dp[i][0] = cnt[i];
		if(i&1) dp[i][0] += cnt[i^1];
		Fo(j, 1, B){
			dp[i][j] = dp[i][j-1];
			if(i&(1<<j)) dp[i][j] += dp[i^(1<<j)][j-1];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	int t;
	cin >> t;
	int allone = 1<<B; allone--;
	while(t--){
		cin >> n;
		fo(i, n) cin >> a[i], cnt[a[i]]++;
		sosdp();
		ll ans = 0;
		fo(i, n) ans += dp[allone^a[i]][B-1], cnt[a[i]] = 0;
		cout << ans << endl;
	}

	return 0;
} 
