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
const int mod = 2e5;
const int N = 3e5;
vi g[N];
int a[N];
void dfs(int u, int par);
//http://codeforces.com/contest/600/problem/E
static int t = 0;
int BLOCK = sqrt(mod);
bool f(pair<int, pii> a, pair<int, pii> b){
    if (a.S.F / BLOCK != b.S.F / BLOCK) return a.S.F < b.S.F;
    return a.S.S < b.S.S;
}

ll sum = 0, occ = 0;
ll ans[N], val[N];
int cnt[N], col[N], rep[N], in[N], out[N], agla[N], pre[N];
set<int> dom;
set<pii> mx;
//ADD , DEL a number and store the sum of max occuring nos in 'sum'
void add(int pos){
    //c is the variable that we are adding here
    int c = rep[pos];
    val[cnt[c]] -= c;
    int pr = pre[cnt[c]];
    int nxt = agla[cnt[c]];
    if (val[cnt[c]] == 0) {
        if (nxt == cnt[c]){
            //this is highest
            occ = pr;
            agla[pr] = pr;
        }
        else{
            pre[nxt] = pr;
            agla[pr] = nxt;
        }
        agla[cnt[c]] = pre[cnt[c]] = -1;
    }
    cnt[c]++;
    val[cnt[c]] += c;

    if (cnt[c] > occ){
        agla[occ] = cnt[c];
        pre[cnt[c]] = occ;
        occ = cnt[c];
    }
    else if (cnt[c] < nxt){
        agla[pr] = cnt[c];
        pre[cnt[c]] = pr;
        agla[cnt[c]] = nxt;
        pre[nxt] = cnt[c];
    }
    agla[occ] = occ;
    sum = val[occ];
}
void del(int pos){
    int c = rep[pos];
    val[cnt[c]] -= c;
    int pr = pre[cnt[c]];
    int nxt = agla[cnt[c]];
    if (val[cnt[c]] == 0) {
        if (nxt == cnt[c]){
            //this is highest
            occ = pr;
            agla[pr] = pr;
        }
        else{
            pre[nxt] = pr;
            agla[pr] = nxt;
        }
        agla[cnt[c]] = pre[cnt[c]] = -1;
    }
    cnt[c]--;
    val[cnt[c]] += c;
    if (cnt[c] > occ){
        agla[occ] = cnt[c];
        pre[cnt[c]] = occ;
        occ = cnt[c];
    }
    else if (cnt[c] > pr){
        agla[pr] = cnt[c];
        pre[cnt[c]] = pr;
        agla[cnt[c]] = nxt;
        pre[nxt] = cnt[c];
    }
    agla[occ] = occ;
    sum = val[occ];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i;
	si(n);
	set<int> dis_col;
	fo (i, n) si(col[i+1]), dis_col.insert(col[i+1]);
	tr(it, dis_col) val[0] += *it;

	fo(i, n-1){
        int u, v;
        si(u); si(v);
        g[u].pb(v);
        g[v].pb(u);
	}
	dfs(1, 0);
	vector< pair<int, pii> > Q;
	Fo(i, 1, n+1) Q.pb( { i, {in[i], out[i]} } );
    sort(Q.begin(), Q.end(), f);
    int L , R, curl, curr;
    curl = curr = 0;
    fo(i, n){
        pair<int, pii> q = Q[i];
        L = q.S.F, R = q.S.S;

        while( curl > L){
            add(curl-1);
            curl--;
        }
        while( curr < R){
            add(curr+1);
            curr++;
        }
        while( curl < L){
            del(curl);
            curl++;
        }
        while( curr > R){
            del(curr);
            curr--;
        }
        ans[q.F] = sum;
    }
    Fo(i, 1, n+1) printf("%I64d ",ans[i]);
	return 0;
}

void dfs(int u, int par){
    in[u] = ++t;
    rep[t] = col[u];
    for(int v:g[u]){
        if (v == par) continue;
        dfs(v, u);
    }
    out[u] = ++t;
    rep[t] = col[u];
}
