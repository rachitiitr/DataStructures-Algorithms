struct node{
	ll ans;
	void leaf(int val){
		ans = val;
	}
	
	void merge(node r, node l){
		ans = r.ans + l.ans;
	}	
	
};
class st{
	int n;
	node* T;
	int* a;
	public:
	#define l(x) 2*x
	#define r(x) 2*x+1
	#define lpart left, lo, mid
	#define rpart right, mid+1, hi
	st() {}
	st(int x){
		a = new int[x];
		clr(a);
		n = 1;
		while(n <= x) n *= 2; n *= 2;
		T = new node[n];
		n = x;
		build(1, 0, n-1);
	}
	st(int *arr, int x){
		a = arr;
		n = 1;
		while(n <= x) n *= 2; n *= 2;
		T = new node[n];
		n = x;
		build(1, 0, n-1);
	}
	void build(int id, int lo, int hi){
		if(lo == hi){
			T[id].leaf(a[lo]);
			return;
		}
		int left = l(id), right = r(id), mid = (lo+hi)/2;
		build(lpart);
		build(rpart);
		T[id].merge(T[left], T[right]);
	}
	void update(int pos, int val){
		update(1, 0, n-1, pos, val);
	}
	void update(int id, int lo, int hi, int pos, int val){
		if(lo==hi and lo==pos){
			a[pos] = val;
			T[id].leaf(a[lo]);
			return;
		}
		int left = l(id), right = r(id), mid = (lo+hi)/2;
		if(pos <= mid) update(lpart, pos, val);
		else update(rpart, pos, val);
		T[id].merge(T[left], T[right]);
	}
	ll query(int x, int y){
		return query(1, 0, n-1, x, y).ans;
	}
	node query(int id, int lo, int hi, int x, int y){
		if(lo==x and hi==y){
			return T[id];
		}
		int left = l(id), right = r(id), mid = (lo+hi)/2;
		if(y <= mid) return query(lpart, x, y);
		else if(x>mid) return query(rpart, x, y);
		node L = query(lpart, x, mid);
		node R = query(rpart, mid+1, y);
		node res;
		res.merge(L, R);
		return res;
	}
};
