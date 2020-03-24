//intersection of horizontal and vertical lines https://www.codechef.com/NOV16/problems/URBANDEV
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_mset;
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
typedef vector<ll>		vll;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vll>		vvl;
const int mod = 1000000007;
const int N = 1e5+12;
using namespace std;
 int cnt[N];
typedef pair<int,int> pii;
 
class CBF
{
public:
	bool operator()(const pii& p1, const pii& p2)const
	{
		return p1.first < p2.first;
	}
};
 
 
vi lo[N], hi[N];
vector< pair<int, pii> > ver[N];
set<int> events;
unordered_map<int, int> hai[2][N];
#define x1 u.F
#define y1 u.S
#define x2 v.F
#define y2 v.S
int n;

struct node{
	pii u,v;
	int o;
	void read(int i){
		si(u.F); si(u.S);
		si(v.F); si(v.S);
        events.insert(x1);
        events.insert(x2);
        if(u.S > v.S or u.F > v.F) swap(u, v);
		find(i);
	}
	void find(int pos){
		if(u.F==v.F){
			o=1;
			ver[u.F].pb({pos, {u.S, v.S}});
		}
		else{ 
			o=0; 
			lo[u.F].pb(u.S);
			hi[v.F].pb(v.S);
		}
        hai[o][u.F][u.S] = 1;
        
        hai[o][v.F][v.S] = 1;
	}
    void change(int i){
       swap(x1, y1); swap(x2, y2);
        if(u.S > v.S or u.F > v.F) swap(u, v);
		find(i);
    }
}seg[N];

void input(){
    int i;
    si(n);
	fo(i, n){
		seg[i].read(i); cnt[i] = 0;
	}
    
}
void reset(){
    int i;
  //  fo(i, N) hai[0][i].clear(), hai[1][i].clear();
    fo(i, N) lo[i].clear(), hi[i].clear(), ver[i].clear();
    events.clear();
    fo(i, n) seg[i].change(i), events.insert(seg[i].x1), events.insert(seg[i].x2);    
    
}
int T = 1;
int inf = mod;
void solve(){
 	int i;
 	
	ll ans = 0;
    
	ordered_mset con;
     int xx;
 
	for(int xx: events){
        //cout<<"AT "<<xx<<endl;
		for(int y: lo[xx])
            con.insert({y, T++});
		
        if(con.empty())continue;
		
		for(pair<int, pii> line: ver[xx]){
			int j = line.F;
			pii span = line.S;
			cnt[j] += con.order_of_key({span.S, inf})
                    - con.order_of_key({span.F-1, inf});
            //cout<<"LINE "<<span.F<<" "<<span.S<<" intersects with "<<cnt[j]<<endl;
			
		}
        for(int y: hi[xx])
            con.erase(con.lower_bound({y, 0}));		
	}
   
 
 }
int main()
{
     int i;

    input();
    fo(i, n){
      int o = seg[i].o;
      cnt[i] -= hai[1-o][seg[i].x1][seg[i].y1];
      cnt[i] -= hai[1-o][seg[i].x2][seg[i].y2];
      
    }
	solve();
    reset();
    //clr(cnt);
    solve();
   
    ll ans = 0;
    fo(i, n) ans += cnt[i];
    ans /= 2;
    pl(ans);
	fo(i, n) printf("%d ",cnt[i]);
}