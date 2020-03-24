#include <bits/stdc++.h>
using namespace std;
class heap{
	vector<int> a;
	#define l(x) 2*x+1
	#define r(x) 2*x+2
	#define p(x) (x-1)/2
	#define null -INT_MAX
	public:
	void add(int x){
		a.push_back(x);
		go(a.size()-1);
	}
	void go(int u){
		if(u == 0) return;
		int P = p(u);
		if(a[P]>a[u]) swap(a[P], a[u]), go(P);
	}
	void heapify(int u){
		int L = l(u), R = r(u), n = a.size();
		if(L>=n and R>=n) return;
		int v = (L<n&&R<n)?(a[L]<=a[R]?L:R):L;
		if(a[u]>a[v]) swap(a[u], a[v]), heapify(v);
	}
	int extract(){
		if (a.empty()){
			cout << "Oops! heap is empty!" << endl;
			return null;
		}
		int ans = a[0];
		if(a.size() == 1) {
			a.clear();
			return ans;
		}
		a[0] = a.back();
		a.pop_back();
		heapify(0);
		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	heap H;
	vector<int> a{13, 1, 10, 34, 42, -10};
	for(int x: a) H.add(x);
	for(int x: a) cout << H.extract() << " ";
	return 0;
} 


