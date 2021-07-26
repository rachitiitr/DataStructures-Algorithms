#include <bits/stdc++.h>
// http://ideone.com/jsXeQn
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
ll a[N];
//Input: Array and queries asking {sum, no}
// of elements less than given x
//log(n) per query
class RangeSum{
	int n;
	vector<long long> A;
	set<pair<long long, int>> my;
	public:
	RangeSum(long long a[], int nn){
		sort(a, a+nn);
		int i;
		n = nn;
		A = {0};
		fo(i, n){
			A.push_back(A[i]+a[i]);
			my.insert({a[i], i+1});
		}
	}
	RangeSum(vector<long long> &a){
		sort(a.begin(), a.end());
		int i;
		n = a.size();
		A = {0};
		fo(i, n){
			A.push_back(A[i]+a[i]);
			my.insert({a[i], i+1});
		}
	}
	//Returns {sum, no} where
	// sum = sum of ele <= val
	// no = # of ele <= val
	pair<long long, int> sum(long long val){
		if(n == 0) return {0, 0};
		auto it = my.lower_bound({val, n+1});
		if(it == my.end()) return {A[n], n};
		if((*it).F == val) return {A[(*it).S], (*it).S};
		return {A[(*it).S-1], (*it).S-1};
	}
	pair<long long, int> sum(long long x, long long y){
		if(x>y) swap(x,y);
		pl p = sum(y);
		pl q = sum(x-1);
		return {p.first-q.first, p.second-q.second};
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	cin >> n;
	fo(i, n) cin >> a[i];
	RangeSum my(a, n);
	cout << my.sum(5).F << " " <<my.sum(5).S << endl;
	cout << my.sum(3, 9).F << " " <<my.sum(3, 9).S << endl;

	return 0;
} 

