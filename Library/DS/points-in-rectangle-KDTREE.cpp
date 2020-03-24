#include <bits/stdc++.h>
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
const int N = 3e5+2;
using namespace std;
 int cnt[N];
typedef pair<int,int> pii;
 
class CompareByFirst
{
public:
	bool operator()(const pii& p1, const pii& p2)const
	{
		return p1.first < p2.first;
	}
};
 
class CompareBySecond
{
public:
	bool operator()(const pii& p1, const pii& p2)const
	{
		return p1.second < p2.second;
	}
};
 
struct QTNode
{	
	int left, right, bottom, top;
	int count;
	QTNode* child[2];
	
	void SplitData(vector<pii>& points, int first, int last, int level)
	{
		this->count = last - first + 1;	
		
		this->left = points[first].first;
		this->right = points[first].first;
		this->bottom = points[first].second;
		this->top = points[first].second;		
		
		if(first == last)
		{
			this->count = 1;
			return;
		}			
				
		for(int i = first + 1; i <= last; i++)
		{
			this->left = min(this->left, points[i].first);
			this->top = max(this->top, points[i].second);
			this->right = max(this->right, points[i].first);
			this->bottom = min(this->bottom, points[i].second);	
		}		
								
		int mid = first + (last - first) / 2;
		if(level & 0x1)
		{
			nth_element(&points[first], &points[mid], &points[last + 1], CompareByFirst());		
		}
		else
		{	
			nth_element(&points[first], &points[mid], &points[last + 1], CompareBySecond());		
		}		
		
		child[0] = new QTNode();
		child[1] = new QTNode();
		child[0]->SplitData(points, first, mid, level + 1);
		child[1]->SplitData(points, mid + 1, last, level + 1);						
	}	
	
	int CountInRect(int _left, int _right, int _bottom, int _top)
	{
		if(	this->left >= _left and 
			this->right <= _right and 
			this->top <= _top and 
			this->bottom >= _bottom)
		{
			return this->count;
		}
		else if(this->left <= _right and 
				this->right >= _left and
				this->top >= _bottom and
				this->bottom <= _top)
		{
			return this->child[0]->CountInRect(_left, _right, _bottom, _top) + this->child[1]->CountInRect(_left, _right, _bottom, _top);
		}
		else
		{
			return 0;
		}
	}
	
	void Traverse()
	{
		cout<<left<<","<<right<<"  "<<bottom<<","<<top<<" # "<<count<<endl;
		if(child[0])
		{
			child[0]->Traverse();
		}
		if(child[1])
		{
			child[1]->Traverse();
		}
	}
};
 
QTNode* buildQTree(vector<pair<int,int> >& points)
{
	QTNode* root = new QTNode();
	root->SplitData(points,0,points.size() - 1, 0);		
	return root;
}
 
template<typename T>
void PrintSet(set<pii, T>& s)
{
	for(set<pii>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout<<i->first<<":"<<i->second<<" ";
	}
	cout<<endl;
}
struct node{
	pii u,v;
	int o;
	void read(){
		cin>>u.F>>u.S;
		cin>>v.F>>v.S;
		if(u > v) swap(u, v);
		find();
	}
	void find(){
		if(u.F==v.F)o=1;
		else o=0;
	}
}seg[N];
map<int,int> hai[2][N];
 void solve(){

 	int i, n;
 	cin>>n;
	ll ans = 0;
	vpii interval[2][2];
	fo(i, n){
		seg[i].read();
		int x = seg[i].o;
		node line = seg[i];
        hai[x][line.u.F][line.u.S] = 1;
        hai[x][line.v.F][line.v.S] = 1;
		if(x){
			// |
			// |   => x is constant
			// |
			interval[x][0].pb({line.u.F, line.u.S});
			interval[x][1].pb({line.v.F, line.v.S+1});
			
            //cout<<x<<" "<<line.u.S<<" "<<line.v.S<<endl;
		}	
		else{
			interval[x][0].pb({line.u.F, line.u.S});
			interval[x][1].pb({line.v.F+1, line.v.S});
            // cout<<x<<" "<<line.u.F<<" "<<line.v.F<<endl;
			
		}
	}
	QTNode *qTree[2][2];
	qTree[0][0] = buildQTree(interval[0][0]);
	qTree[0][1] = buildQTree(interval[0][1]);
	qTree[1][0] = buildQTree(interval[1][0]);
	qTree[1][1] = buildQTree(interval[1][1]);
	fo(i, n){
		node line = seg[i];
		int x = line.o;
		cnt[i] = qTree[1-x][0]->CountInRect(0, line.v.F, 0, line.v.S);
		cnt[i] -= qTree[1-x][1]->CountInRect(0, line.v.F, 0, line.v.S);
       // cout<<1-x<<" ";
		//if(x){
			cnt[i] -= hai[1-x][line.u.F][line.u.S]+hai[1-x][line.v.F][line.v.S];
           // cout<<line.u.S<<" "<<line.v.S<<endl;
		//}else{
		//	cnt[i] -= hai[1][line.u.F]+hai[1][line.u.F];
           // cout<<line.u.F<<" "<<line.v.F<<endl;
		//}
		
		ans += cnt[i];
	}
     cout<<endl;
	cout<<ans/2<<endl;
	fo(i, n) cout<<cnt[i]<<" ";
 	
 }
int main()
{
	solve();
}
 
 
