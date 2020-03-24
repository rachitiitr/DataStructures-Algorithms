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
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
/*
Input: A vector of intervals in any random order
Output: 
1. Removes redundant intervals ie remove [2,3] if [1,4] is present.
2. does NOT merge overlapping intervals.
3. Sorted in ascending order of starting interval which are distinct.
*/
void fun_interval(vpii &in){
	int i = 1, n = in.size();
	sort(in.begin(), in.end(), [](pii x, pii y){if(x.F == y.F)return x.S>y.S;return x.F<y.F;});
	vpii took = {in[0]};
	int hi = in[0].S;
	Fo(i, 1, n){
		if(hi>=in[i].S)continue;
		hi = in[i].S;
		took.pb(in[i]);
	}
	in.clear();
	for(pii x: took) in.pb(x);
//	Uncomment the following lines, if you wish to sort intervals on asc order of HI value.
//	for(auto& x: in) swap(x.F,x.S);  // [lo, hi] is converted to [hi, lo].
//	sort(in.begin(), in.end(), [](pii x, pii y){return x.F<y.F;});
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	cin >> n;
	vpii in(n, {0,0});
	fo(i, n) cin >> in[i].F >> in[i].S ;
	fun_interval(in);
	for(pii x: in) cout << x.F << " " << x.S << endl;

	return 0;
} 
/*
Input:
5
1 4
0 3
2 3
0 5
3 9
Output:
0 5
3 9
*/
