
// query l to r range for the no of integers between x and y
#include <iostream>
using namespace std;
int T = 1;
const int N = 1e6;
const int MX = N;
struct node{
	int l, r, cnt;	
}t[100*MX];
int root[N], a[N];
int build(int lo, int hi){
	int id = T++;
	if(lo == hi) return id;
	int  mid = (lo+hi)/2;
	t[id].l = build(lo, mid);
	t[id].r = build(mid+1, hi);
	return id;
}
int update(int rt, int lo, int hi, int val){
	int id = T++;
	t[id] = t[rt]; t[id].cnt++;
	if(lo == hi) return id;
	int mid = (lo+hi)/2;
	if(val <= mid) t[id].l = update(t[rt].l, lo, mid, val);
	else t[id].r = update(t[rt].r, mid+1, hi, val);
	return id;
}
int query(int rt, int lo, int hi, int x, int y){
	if(x==lo and y==hi) return t[rt].cnt;
	int mid = (lo+hi)/2;
	if(y <= mid) return query(t[rt].l, lo, mid, x, y);
	else if (x > mid) return query(t[rt].r, mid+1, hi, x, y);
	return query(t[rt].l, lo, mid, x, mid)	+ query(t[rt].r, mid+1, hi, mid+1, y);
}
int main() {
	int i, n, q;
	cin >> n >> q;
	for(i = 0; i < n; i++) cin >> a[i+1];
	root[0] = build(0, MX);
	for(i = 1; i <= n; i++){
		root[i] = update(root[i-1], 0, MX, a[i]);
	}
	while(q--){
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		cout << query(root[r], 0, MX, x, y) - query(root[l-1], 0, MX, x, y) << endl;
	}
	return 0;
}