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
struct compar{
	//priority queue 
	//u need top element.. sort such 
	//that ur element comes at last
	bool operator() (pii a, pii b){
		if (a.F != b.F)
			return a.F > b.F;
		return a.S < b.S;
	}	
};
//UNDIRECTED GRAPH
class Dijkstra{
	int n, m;
	ll *dis;
	bool *vis;
	int *par;
	ll inf;
	priority_queue<pii, vector<pii>,compar> Q;
	vpii *G;
	public:
		void setVertices(int no){
			n = no;
			G = new vpii[n+1];
			dis = new ll[n+1];
			vis = new bool[n+1];
			par = new int[n+1];
			inf = 1e18;
			
		}
		void setEdges(int no){
			m = no;
		}
		void addEdge(int u, int v, int w){
			G[u].pb({w, v});
			//UNDIRECTED-GRAPH
			G[v].pb({w, u});
		}
		ll shortestPath(int source, int sink){
			int i;
			for(i=1; i<=n; i++)
				dis[i] = inf, vis[i] = 0;
			dis[source] = 0;
			Q.push({0, source});
			while(!Q.empty()){
				pii cur = Q.top(); Q.pop();
				if (vis[cur.S]) continue;
				vis[cur.S] = 1;
				dis[cur.S] = cur.F;
				for(pii x: G[cur.S]){
					int to = x.S, w = x.F;
					Q.push({cur.F+w, to});
				}
				
			}
			if (dis[sink] != inf) return dis[sink];
			return -1;
		}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, n, m;
	cin>>n>>m;
	Dijkstra A;
	A.setVertices(n);
	A.setEdges(m);
	while(m--){
		int u, v, w;
		cin>>u>>v>>w;
		A.addEdge(u, v, w);
	}
	A.pathOfShortestPath(1, n);
	return 0;
} 


