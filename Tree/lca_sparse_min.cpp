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
const ll mod = 1e16;
const int N = 1004, M = 1e5+3;
vi g[M];
vpii tic[M];

//BEGINS
//LCA implemented with sparse table..
//dp[u][i] gives uth node se 2^i length ke parent tak min value in node.
ll dp[M][20];
int lvl[M], P[M][20];
int vis[N];

void dfs(int u, int p){
	P[u][0] = p;
	lvl[u] = 1+lvl[p];
	for(int v: g[u]){
		if (v != p) dfs(v, u);
	}
}
ll get(int u, int l){
    int lg = 0, i;
    if (l == 1) return dp[u][0];
    //cout<<"from "<<u<<" seg of size "<<l<<" ";
    int nlev = lvl[u]-l+1;
    while( (1<<lg) <= l ) lg++;
    lg--;
    ll ans = mod;
    for(i = lg; i>=0; i--){
        if (lvl[u] - (1<<i) + 1 >= nlev )
            ans = min(ans, dp[u][i]), u = P[u][i];
    }
    return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (0){
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
	int i,n,k,j,m,u,v,w,x;
	int t;
	cin>>n>>m;
    fo(i, n-1){
        cin>>u>>v;
        g[v].pb(u);
        g[u].pb(v);
    }
    fo(i, m){
        cin>>u>>k>>w;
        tic[u].pb({k, w});
    }
    Fo(i, 0, 20)
        Fo(j, 0, n+1) P[j][i] = -1;
    lvl[0] = -1;
    dfs(1, 0);

    Fo(i, 1, 20){
        Fo(j, 1, n+1){
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
        }
    }

    int q;
    cin >> q;
    set<pii> city;
    Fo(i, 1, n+1) city.insert({lvl[i], i});
    tr(it, city){
        pii cur = *it;
        int lev = cur.F;
        u = cur.S;
        if (u == 1){
            //cout<<1<<" "<<0<<endl;
            dp[u][0] = 0;
            continue;
        }
        dp[u][0] = mod;
	//Find dp[u][0] using dp[p[u][0]][*]
        for(pii t: tic[u]){
            int dis = min(lev, t.F); ll w = t.S;
            dp[u][0] = min(dp[u][0], w + get(P[u][0], dis));
        }
        //cout<<u<<" "<<dp[u][0]<<endl;
	//DYNAMIC UPDATION
        Fo(i, 1, 20){
            if (P[u][i-1] != -1){
                dp[u][i] = min(dp[u][i-1], dp[P[u][i-1]][i-1]);
            }
            else
                dp[u][i] = dp[u][i-1];
        }
    }
    fo(i, q){
        cin>>x;
        cout<<dp[x][0]<<endl;
    }


	return 0;
}


