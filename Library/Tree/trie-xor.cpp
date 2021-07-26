//http://codeforces.com/contest/282/submission/21362419

void bin(ll n, vi &a){
	vi b;
	int i;
	while(n){
		b.pb(n%2);
		n /= 2;
	}
	a.clear();
	while(b.size()!=41) b.pb(0);
	fo(i, b.size()){
		a.pb(b[b.size()-i-1]);
	}
}
struct node{
	int val, to;
	void init(){
		val = to = 0;
	}
}trie[N][2];
static int t = 0;
void add(ll x){
	vi a;
	bin(x, a);
	int rt = 0;
	int pos = 0;
	while(pos<a.size()){
		if (trie[rt][a[pos]].val == 0){
			trie[rt][a[pos]].to = ++t;
			// cout<<"not found "<<a[pos]<<",";
		}
		// else cout<<" found "<<a[pos]<<",";
		
		trie[rt][a[pos]].val++;
		rt = trie[rt][a[pos]].to;
		pos++;
	}
}
ll get(ll val){
	vi a; bin(val, a);
	vi res;
	int pos = 0, rt = 0;
	while(pos<a.size()){
		
		int find = 1-a[pos];
		if (trie[rt][find].val != 0){
			res.pb(find);
			// cout<<"found "<<find<<" "<<"for "<<a[pos]<<endl;
			rt = trie[rt][find].to;
		}
		else{
			res.pb(1-find);
			rt = trie[rt][1-find].to;
			// cout<<"not found "<<find<<" "<<"for "<<a[pos]<<endl;
		}
		pos++;
	}
	ll ans = 0;
	// cout<<res.size()<<endl;
	int i;
	fo(i, res.size()){
		ans = 2*ans+res[i];
	}
	return ans;
}
void del(int val){
	vi a; bin(val, a);
	vi res;
	int pos = 0, rt = 0;
	while(pos<a.size()){
		trie[rt][a[pos]].val--;
		rt = trie[rt][a[pos]].to;
		pos++;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n;
	cin>>n;
	fo(i, N) trie[i][0].init(), trie[1][0].init();
	fo(i, n) cin>>a[i];
	add(0);
	ll res1 = 0;
	ll ans = 0;
	ll res = 0;
	a[n] = 0;
	for(i=n-1; i>=0; i--) res1 ^= a[i];
	for(i=n-1; i>=0; i--) ans = max(ans, res1^get(res1)), res1 ^= a[i], res ^= a[i], add(res);
	// fo(i, n) res ^= a[i], ans = max(ans, res^get(res)), del(res1), res1 ^= a[i+1];
	ans = max(ans, 0LL+get(0));
	
	cout<<ans<<endl;
	return 0;
} 

