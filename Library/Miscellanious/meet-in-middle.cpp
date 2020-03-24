//http://codeforces.com/contest/525/problem/E
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
int a[N];
vi rep(int no, int len, int base){
	vi ans;
	while(no){
		ans.pb(no%base);
		no /= base;
	}
	while((int)ans.size() != len) ans.pb(0);
	reverse(all(ans));
	return ans;
}
map<ll, ll> cnt[30];
ll fac[20];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j, mask;
	ll s, ans = 0;
	cin>>n>>k>>s;
	fo(i, n) cin>>a[i];
	int len = n/2, left = n-len;
	int lim = pow(3, len);
	fo(i, n+1) cnt[i].clear();
	fac[1] = 1;
	Fo(i, 2, 20) fac[i] = fac[i-1]*i;
	fo(mask, lim){
		vi bit = rep(mask, len, 3);
		int used = 0;
		ll sum = 0;
		fo(i, bit.size()){
			int dig = bit[i];
			if(dig==0)continue;
			else if(dig==1) sum += a[i];
			else if (a[i]<20)sum += fac[a[i]], used++;
			else if(a[i]>=20) {
				sum = -1;
				break;
			}
		}
		if(sum>=0){
			// for(int x:bit) cout<<x;
			// cout<<" ";
			// cout<<used<<" "<<sum<<endl;
			cnt[used][sum]++;
		}
	}
	//len to n-1
	
	
	lim = pow(3, left);
	fo(mask, lim){
		vi bit = rep(mask, left, 3);
		int used = 0;
		ll sum = 0;
		fo(i, bit.size()){
			int dig = bit[i];
			if(dig==0)continue;
			else if(dig==1) sum += a[i+len];
			else if (a[i+len]<20)sum += fac[a[i+len]], used++;
			else if(a[i+len]>=20) {
				sum = -1;
				break;
			}
		}
		if(sum>=0){
			int remk = k-used;
			ll need = s-sum;
			while(remk>=0 and need>=0 ){
				if(cnt[remk].count(need))
					ans += cnt[remk][need];
				remk--;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
} 

