#include <bits/stdc++.h>
// http://www.spoj.com/problems/HORRIBLE/
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
const int N = 3e5, M = N;
#define pnode node*
struct node{
	int key;
	ll val;
	ll sum;
	ll lazy;
	int prior;
	int size;
	pnode l;
	pnode r;
};
pnode init(int val){
	pnode res = new node;
	res->prior = rand();
	res->l = res->r = NULL;
	res->val = val;
	res->sum = val;
	res->size = 1;
	res->lazy = 0;
	return res;
}
ll sm(pnode t){
	if(!t) return 0;
	return t->sum;
}
int sz(pnode t){
	if(t == NULL) return 0;
	else return t->size;
}
void reform(pnode t){
	if(!t)return;
	t->sum = sm(t->l) + sm(t->r) + t->val;
}
void push(pnode t){
	if(!t) return;
	if(t->lazy){
		if(t->l){
			swap(t->l->l, t->l->r);
			t->l->lazy ^= 1;
		}
		if(t->r){
			swap(t->r->l, t->r->r);
			t->r->lazy ^= 1;
		}
		t->lazy = 0;
	}
}
void upd_sz(pnode t){
	if(t) t->size = sz(t->l) + 1 + sz(t->r);
}
void split(pnode t, pnode &l, pnode &r, int pos){
	if(t == NULL) {l=r=NULL; return ;}
	push(t);
	int tot = sz(t->l);
	if(tot >= pos) split(t->l, l, t->l, pos), r = t;
	else split(t->r, t->r, r, pos-tot-1), l = t;
	upd_sz(t);
	reform(t);
}
void merge(pnode &t, pnode l, pnode r){
	push(l);
	push(r);
	if(!l or !r) t = l?l:r;
	else if(l->prior >= r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_sz(t);
	reform(t);
}
void range_update(pnode &t, int x, int y){
	pnode L;
	pnode mid;
	pnode R;
	split(t, L, mid, x-1);
	split(mid, t, R, y-x+1);
	swap(t->l, t->r);
	t->lazy = 1;
	merge(mid, t, R);
	merge(t, L, mid);
}
ll range_query(pnode &t, int x, int y){
	pnode L;
	pnode mid;
	pnode R;
	split(t, L, mid, x-1);
	split(mid, t, R, y-x+1);
	ll ans = t->val;
	merge(mid, t, R);
	merge(t, L, mid);
	return ans;
}
// void insert_at(pnode &t, int pos, int val){
// 	pnode L;
// 	pnode mid;
// 	pnode R;
// 	split(t, L, mid, pos-1);
// 	split(mid, t, R, 1);
// 	t->val = val;
// 	merge(mid, t, R);
// 	merge(t, L, mid);
// }
// void print(pnode t){
// 	if(!t)return;
// 	print(t->l);
// 	cout << t->val << " ";
// 	print(t->r);
// }
// int delete_at(pnode &t, int pos){
// 	node *L, *mid, *R;
// 	split(t, L, mid, pos-1);
// 	split(mid, t, R, 1);
// 	node *tem = t;
// 	int val = t->val;
// 	merge(t, L, R);
// 	free(tem);
// 	return val;
// }
void clear(pnode &t){
	if(t == NULL)return;
	clear(t->l);
	clear(t->r);
	free(t);
}
//=======================

vi g[N];
int a[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));
	freopen("rev.in", "r", stdin);
	freopen("rev.out", "w", stdout);
	int i,n,k,j,q,x,y;
	q = 1;
	pnode t;
	int v;
	si(n); si(q);
	// clear(t);
	t = init(1);
	fo(i, n-1) merge(t, t, init(i+2));
	while(q--){
		int ty;
		si(x);
		si(y);
		si(k);
		assert(x <= y);
		assert(k<=n);
		range_update(t, x, y);
		// cout << range_query(t, k, k) << endl;
		pi(range_query(t, k, k));
	}
	return 0;
} 

