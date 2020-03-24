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
//Takes query values in increasing order
//Add lines in sorted order
class ConvexHull{
	int ptr;
	typedef pii Line;
	vector<Line> lines;
	public:
		ConvexHull(){
			ptr = 0;
			lines.clear();
		}
		int f(Line l, int x){
			return l.F*x+l.S;
		}
		bool bad(Line l1, Line l2, Line l3){
			return (l3.S-l1.S)*(l1.F-l2.F) <= (l1.F-l3.F)*(l2.S-l1.S);
		}
		void addLine(Line l3){
			lines.pb(l3);
			while(lines.size()>=3){
				int tot = lines.size();
				Line l3 = lines[tot-1];
				Line l2 = lines[tot-2];
				Line l1 = lines[tot-3];
				if (bad(l1, l2, l3)){
					lines.erase(lines.end()-2);
				}
				else break;
			}
		}
		//Returns Minimum 
		//Query values must be in non-decreasing order
		//Otherwise use Binary Search (Maintain the end points of lines)
		int get(int x){
			if (ptr >= lines.size()) ptr = lines.size()-1;
			while(ptr < lines.size()-1 and f(lines[ptr], x) > f(lines[ptr+1], x))
				ptr++;
			return f(lines[ptr], x);
		}
};
//END
bool f(pii a, pii b){
	if (a.F != b.F) return a.F > b.F;
	return a.S < b.S;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n;
	vpii data;
	cin>>n;
	fo(i, n){
		int m, c;
		cin>>m>>c;
		data.pb({m, c});
	}
	sort(data.begin(), data.end(), f);
	ConvexHull A;
	fo(i, n) A.addLine(data[i]);
	cin>>n;
	vi points;
	fo(i, n){
		int x;
		cin>>x;
		points.pb(x);
	}
	sort(points.begin(), points.end());
	for(int x: points)
		cout<<x<<" "<<A.get(x)<<endl;

	
	return 0;
} 


