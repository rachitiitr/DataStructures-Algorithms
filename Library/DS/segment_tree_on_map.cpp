#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
map<int, long long> my[N];
void update(int st, int lo, int hi, int pos, int val){
	my[st][val]++;
	if(lo == hi){
		return;
	}
	int l = 2*st, r = l+1, mid = (lo+hi)/2;
	if(pos>mid) update(r, mid+1, hi, pos, val);
	else update(l, lo, mid, pos, val);
}
long long query(int st, int lo, int hi, int x, int y, int val){
	if(lo == x and hi == y){
		return my[st][val];
	}
	int l = 2*st, r = l+1, mid = (lo+hi)/2;
	if(x>mid) return query(r, mid+1, hi, x, y, val);
	else if(y<=mid) return query(l, lo, mid, x, y, val);
	return query(l ,lo , mid, x, mid, val) + query(r, mid+1, hi, mid+1, y, val);
}

int main() {
	int n, i, q, k, l, t, r;
	cin >> n >> q;
	while(q--){
		cin >> t >> l >> r;
		if(t == 1){
			//add l to a[r]
			update(1, 0, n-1, r-1, l);
		}
		else{
			//count of k from a[l] to a[r].
			cin >> k;
			cout << query(1, 0, n-1, l-1, r-1, k) << endl;
		}
	}
	return 0;
}