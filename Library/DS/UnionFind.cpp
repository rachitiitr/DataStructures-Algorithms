class UnionFind{
	//1-based indexing
	int n, m;
	int *p, *z;
	public:
		UnionFind(int no){
			n = no;
			p = new int[n+10];
			z = new int[n+10];
			int i;
			Fo(i, 1, n+1) 
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
		int com(){
			int i;
			int ans = 0;
			Fo(i, 1, n+1) ans += p[i] == i;
			return ans;
		}
};
