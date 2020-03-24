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
const int mod = 1000000007;
const int N = 2e6;
vi g[N];
int pos_;
ll a[N], MX;
int dp[N], b1[N], b2[N], p1[N], p2[N], from[N];
int L, R;
//http://codeforces.com/problemset/problem/474/E
//pos_ is the 'i' in a[i] while adding a[i] to BIT.
//p1[pos] represents what position in array gives the max till pos.
void add1(int pos, int val){
	while(pos < N){
		if (b1[pos] <= val) b1[pos] = val, p1[pos] = pos_;
		pos += pos&-pos;
	}	
}
void add2(int pos, int val){
	pos = MX-pos+1;
	while(pos < N){
		if (b2[pos] <= val) b2[pos] = val, p2[pos] = pos_;
		pos += pos&-pos;
	}	
}
int get1(int pos){
	int ans = -1;
	while(pos){
		if (b1[pos] > ans) ans = b1[pos], L = p1[pos];
		ans = max(b1[pos], ans);
		pos -= pos&-pos;
	}	
	return ans;
}
int get2(int pos){
	pos = MX-pos+1;
	int ans = -1;
	while(pos){
		if (b2[pos] > ans) ans = b2[pos], R = p2[pos];
		pos -= pos&-pos;
	}	
	return ans;
}
set<ll> sett;
map<ll, int> mep;
map<int, ll> at;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,d;
	cin >> n >> d;
	fo(i, n){
		cin>>a[i];
		sett.insert(a[i]);
	}
	int pos = 0;
	tr(it, sett) mep[*it] = ++pos, at[pos] = *it;
	i = 0;
	MX = mep[*sett.rbegin()];
	pos_ = 1;
	fo(i, n)
		add1(mep[a[i]], 1),
		add2(mep[a[i]], 1);
	Fo(i, 1, n){
		pos_ = i+1; L = R = 0;
		auto it = sett.lower_bound(a[i]-d);
		int left = 1, right = 1;
		if (*it != a[i]-d){
			if (it == sett.begin()) left = 0; 
			else it--;	
		}
		if (left) left = get1( mep[*it]);
		it = sett.lower_bound(a[i]+d);
		if (it == sett.end()) right = 0;
		if (right) right = get2(mep[*it]);
		int cur = max(left, right);
		
		if (cur>-1){
			from[i+1] = cur==left?L:R;
			cur++;
			dp[i] = cur;
			add1(mep[a[i]], cur);
			add2(mep[a[i]], cur);
		}
	}
	
	int cur = n, res = -1;
	fo(i, n) if (res < dp[i]) res = dp[i], cur = i+1;
	cout<<dp[cur-1]<<endl;
	from[1] = 0;
	vi ans;
	while(cur){
		ans.pb(cur);
		cur = from[cur];
	}
	fo(i, ans.size()) cout<<ans[(int)ans.size()-i-1]<<" ";

	return 0;
} 

