//sliding window maximum
//https://people.cs.uct.ac.za/~ksmith/articles/sliding_window_minimum.html
//http://codeforces.com/problemset/problem/372/C
#include <bits/stdc++.h>
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
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vll>		vvl;
const int mod = 1000000007;
const int N = 3e5;
vi g[N];
ll a[N], b[N], t[N];
ll dp[3][N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,m,d;
	cin>>n>>m>>d;
	fo(i, m) cin>>a[i]>>b[i]>>t[i];
	int cur = 1, pre = 0;
	Fo(i, 1, n+1)
		dp[cur][i] = b[m-1]-abs(a[m-1]-i);
	swap(cur, pre);
	Fo(i, m-2, -1){
		deque<pll> window;
		ll dt = t[i+1]-t[i];
		dt *= d;
		k = min(n-1LL, dt);
		//moving from right to left
		//initially install [n-k+1, n] 
		//j-k to j+k
		Fo(j, n, n-k){
			while(!window.empty() and window.back().F <= dp[pre][j])
				window.pop_back();	
			window.pb({dp[pre][j], j});
		}
		Fo(j, n, 0){
			
			int x = j-k;
			//add j-k to window
			if (x>0) {
				while(!window.empty() and window.back().F <= dp[pre][x])
					window.pop_back();
				window.pb({dp[pre][x], x});
			}
			//remove elements at pos > j+k
			while(!window.empty() and window.front().S > j+k) window.pop_front();
			dp[cur][j] = b[i]-abs(a[i]-j) + window.front().F;
		}
		swap(cur, pre);
	}
	ll ans = -1e17;
	Fo(i, 1, n+1) ans = max(ans, dp[pre][i]);
	cout<<ans<<endl;
	return 0;
} 

