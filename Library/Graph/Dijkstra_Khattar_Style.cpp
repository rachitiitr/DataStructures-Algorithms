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
#define clr(x) memset(x, 0, sizeof(x))
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
const int N = 2e5;
vi g[N];
int a[N];

int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
//http://codeforces.com/problemset/problem/545/E
//Begins
//Works for 0/1 based index
//Stores the edges used in shortest paths

struct f{
    bool operator()(pair<ll, pii> a, pair<ll, pii> b){
        if (a.F != b.F) return a.F > b.F;
        if (a.S.S != b.S.S) return W[a.S.S] > W[b.S.S];
        return a.S.F < b.S.F;

    }
};
class Dijkstra{
    int n, m;
    vi *G;
    set<int> res;
    int *vis, *U, *V;
    int *W;
    ll *dis;

    typedef pair<ll, pii> node;
    public:
        void init(int no, int edges){
            n = no;
            m = edges;
            U = new int[m+3];
            V = new int[m+3];
            W = new int[m+3];
	    dis = new ll[m+3];
            G = new vi[n+3];
            vis = new int[n+3];
            int i;
            fo(i, n+1) vis[i] = 0;
            clr(vis);
        }

        int adj(int u, int e){
            return u == U[e]? V[e]:U[e];
        }
        void addEdge(int pos, int u, int v, int w){
            U[pos] = u;
            V[pos] = v;
            W[pos] = w;
            G[u].pb(pos);
            G[v].pb(pos);
        }
        void compute(int source){
            priority_queue< node, vector<node>, f > Q;
            Q.push({0, {source, -1}});

            while(!Q.empty()){
                node cur = Q.top(); Q.pop();
                if (vis[cur.S.F]) continue;
                vis[cur.S.F] = 1;
                dis[cur.S.F] = cur.F;
                res.insert(cur.S.S);
                for(int e: G[cur.S.F]){
                    int to = adj(cur.S.F, e);
                    int w = W[e];
                    Q.push({cur.F+w, {to, e}});
                }
            }
            res.erase(-1);
            ll sum = 0;
            tr(it, res) sum += W[*it];
            cout<<sum<<endl;
            tr(it, res) cout<<*it<<" ";

        }
};
//END
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n, m;
    Dijkstra A;
    cin>>n>>m;
    A.init(n, m);
    fo(i, m){
        int u, v, w;
        cin>>u>>v>>w;
        A.addEdge(i+1, u, v, w);
    }
	int u;
	cin>>u;
	A.compute(u);
	return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

