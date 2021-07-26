#include <bits/stdc++.h>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
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
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 2e6, M = N;
//=======================
struct node{
	ll ans;
	int left, right, len;
	void leaf(int val){
		ans = left = right = val;
		len = 1;
	}
	
	void merge(node r, node l){
		ans = r.ans + l.ans;
		len = r.len + l.len;
		
		ans += l.right * 1LL * r.left;
		
		left = l.left;
		right = r.right;
		
		if(l.left == l.len) left += r.left;
		if(r.right == r.len) right += l.right;
	}	
	
};
class st{
	int n;
	node* T;
	int* a;
	public:
	#define l(x) 2*x
	#define r(x) 2*x+1
	#define lpart left, lo, mid
	#define rpart right, mid+1, hi
	st() {}
	st(int x){
		a = new int[x];
		for(int i = 0; i < x; i++) a[i] = 1;
		n = 1;
		while(n <= x) n *= 2; n *= 2;
		T = new node[n];
		n = x;
		build(1, 0, n-1);
	}
	st(int *arr, int x){
		a = arr;
		n = 1;
		while(n <= x) n *= 2; n *= 2;
		T = new node[n];
		n = x;
		build(1, 0, n-1);
	}
	void build(int id, int lo, int hi){
		if(lo == hi){
			T[id].leaf(a[lo]);
			return;
		}
		int left = l(id), right = r(id), mid = (lo+hi)/2;
		build(lpart);
		build(rpart);
		T[id].merge(T[left], T[right]);
	}
	void update(int pos, int val){
		update(1, 0, n-1, pos, val);
	}
	void update(int id, int lo, int hi, int pos, int val){
		if(lo==hi and lo==pos){
			a[pos] = val;
			T[id].leaf(a[lo]);
			return;
		}
		int left = l(id), right = r(id), mid = (lo+hi)/2;
		if(pos <= mid) update(lpart, pos, val);
		else update(rpart, pos, val);
		T[id].merge(T[left], T[right]);
	}
	ll query(int x, int y){
		return query(1, 0, n-1, x, y).ans;
	}
	node query(int id, int lo, int hi, int x, int y){
		if(lo==x and hi==y){
			return T[id];
		}
		int left = l(id), right = r(id), mid = (lo+hi)/2;
		if(y <= mid) return query(lpart, x, y);
		else if(x>mid) return query(rpart, x, y);
		node L = query(lpart, x, mid);
		node R = query(rpart, mid+1, y);
		node res;
		res.merge(L, R);
		return res;
	}
};

vi g[N];
int a[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	int q, L, R, type, l, r, x, y;
	cin >> n >> q >> L >> R;
	
	L--;
	
	st A(n), B(n);
	
	while(q--){
		cin >> type >> l >> r;
		if(type == 1){
			l--;
			//a[l] = r;
			if(r <= L) A.update(l, 1);
			else A.update(l, 0);
			
			if(r <= R) B.update(l, 1);
			else B.update(l, 0);
		}
		else{
			l--; r--;
			cout << B.query(l, r) - A.query(l, r) << endl;
		}
		
	}
	return 0;
} 

/* INPUT:
5 6 1 10
1 1 2
2 1 5 
1 3 11
1 4 3
2 3 5
2 1 5
*/
