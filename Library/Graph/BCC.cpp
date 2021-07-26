class Bcc{
  vector<int> num,inS;
  stack<int> roots,st;
  int cnt;
public:
  vv<int> bcc,tree;
  vector<int> brdg,inv;
  void dfs(const vv<int> &g,const vector<pii> &es,int v,int e){
    num[v]=++cnt;
    st.push(v); inS[v]=1; roots.push(v);
    for(const int &i:g[v])if(i!=e){
	int w=es[i].X+es[i].Y-v;
	if(!num[w]){
	  dfs(g,es,w,i);
	}else if(inS[w]){
	  while(num[roots.top()]>num[w]) roots.pop();
	}
      }
    if(v==roots.top()){
      brdg.pb(e);
      bcc.pb(vector<int>());
      while(1){
	int w=st.top(); st.pop(); inS[w]=0;
	bcc.back().pb(w);
	if(v==w) break;
      }
      roots.pop();
    }
  }
  
  Bcc(vv<int> &g,vector<pii> es){
    const int n=g.size();
    num.resize(n); inS.resize(n);
    int cnt=0;
    rep(i,n)if(!num[i]){
      dfs(g,es,i,-1);
      brdg.pop_back();
    }
    const int m=bcc.size();
    inv.resize(n);
    rep(i,m) for(const int &v:bcc[i]) inv[v]=i;
    for(pii &p:es){p.X=inv[p.X]; p.Y=inv[p.Y];}
    //sort(all(es)); UNIQUE(es);
    tree.resize(m); //tedge.resize(m);
    int i=0;
    for(const pii &p:es){
      if(p.X!=p.Y){
	tree[p.X].pb(p.Y);
	tree[p.Y].pb(p.X);
	// tedge[p.X].pb(i);
	// tedge[p.Y].pb(i);
      }
      ++i;
    }
  }
};
