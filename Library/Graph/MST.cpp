class UnionFind{
	int n, m;
	int *p, *z;
	public:
		UnionFind(int no){
			n = no;
			p = new int[n+10];
			z = new int[n+10];
			int i;
			fo(i, n+1) 
				p[i] = i, z[i] = 0;
		}
		//Returns 1 if u and v are in different regions
		//0 otherwise
		bool addEdge(int u, int v){
			u = get(u);
			v = get(v);
			if (u == v) return 0;
			if (z[u] < z[v]) p[u] = v;
			else if (z[u] > z[v]) p[v] = u;
			else p[u] = v, z[v]++;
			return 1;
		}
		
		int get(int v){
			if (v == p[v]) return v;
			return p[v] = get(p[v]);
		}
	
};
bool f(pair<int, pii> a, pair<int, pii> b){
	return a.F < b.F;
}
class MST{
	int n, m;
	typedef pair<int, int> pii;
	#define pb push_back
	typedef pair<int, pii> edge;
	vector<edge> Edges;
	UnionFind *forest;
	vector<edge> res;
	public:
		MST(int size){
			n = size;
			forest = new UnionFind(n);
		}
		void addEdge(int u, int v, int w){
			Edges.pb({w, {u, v}});
		}
		void compute(){
			sort(Edges.begin(), Edges.end(), f);
			for(edge E:Edges){
				if (forest->addEdge(E.S.F, E.S.S))
					res.pb(E);
			}
		}
		void out(){
			int sum = 0;
			for(edge E: res)
				sum += E.F;
			cout<<sum<<endl;
		}
	
	
};
