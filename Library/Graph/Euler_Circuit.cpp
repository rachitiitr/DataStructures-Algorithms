//http://codeforces.com/problemset/problem/723/E
//EULER - TOUR  -> UNDIRECTED and DIRECTED GRAPH
//for undirected i needed to mark edges that i have traversed
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
const int N = 304;
vpii g[N];
set<int> has[N];
ll a[N], vis[N], cnt[N], in[N], mark[N*N];
vi ans;
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
void go(int u, int par){
    vis[u] = 1;
    while(cnt[u] < (int)g[u].size()){
        cnt[u]++;
        if (mark[g[u][cnt[u]-1].S]) continue;
        else mark[g[u][cnt[u]-1].S] = 1, go(g[u][cnt[u]-1].F, u);
    }
    ans.pb(u);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, t, i, u,j, v, w;
	//freopen("input.txt", "r". stdin);
	//freopen("output.txt", "w". stdout);
	cin>>t;
	while(t--){
        cin>>n>>m;
        ans.clear();
        Fo(i, 0, n+1) g[i].clear(), has[i].clear(), in[i] = cnt[i] = vis[i] = 0;
        fo(i, m){
            cin>>u>>v;
            g[u].pb({v, i});
            g[v].pb({u, i});
            mark[i] = 0;
            has[u].insert(v);
            has[v].insert(u);
            in[v]++;
            in[u]++;
        }
        int x = m;
        //add pseudo-vertex
        int res = 0;
        Fo(i, 1, n+1) res += 1 - (in[i]%2);
        Fo(i, 0, n+1) if (in[i]&1) mark[x] = 0, g[i].pb({0, x}), g[0].pb({i, x++});

        //graph has all vertices with even degree
        //finding euler circuit makes sure all even degree vertices
        //have equal no of incoming and outgoing edges
        //later on removing extra edges we added
        // will not affect even degree vertices :D
        Fo(i, 1, n+1){
            if (!vis[i]){
                vis[i] = 1;
                go(i, -1);
                ans.pb(i);
            }
        }
        cout<<res<<endl;
        reverse(all(ans));
        fo(i, (int)ans.size()-1){
            if (1==0 or has[ans[i]].find(ans[i+1]) != has[ans[i]].end()){
                cout<<ans[i]<<" "<<ans[i+1]<<endl;
            }
        }

	}



	return 0;
}

