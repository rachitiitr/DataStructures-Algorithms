//1-d bit 
int valR[N], valL[N], bit[N];
map<int, int> id;
void add(int x){
	while(x<N){
		bit[x]++;
		x += x&(-x);
	}
}
int query(int x){
	int ans = 0;
	while(x){
		ans += bit[x];
		x -= x&(-x);
	}
	return ans;
}
void suffix(){
	set<int> no;
	//for suffix queries
	//add all no's in the set that you will add + query
	//otherwise use lower_bound to find the correct id
	fo(i, n) no.insert(valL[i]);
	fo(i, n) no.insert(valR[i]);
	int pos = 1;
	//give IDs in descending order so that
	//suffix is handles as prefix
	for(auto it = no.rbegin(); it != no.rend(); ++it)
		id[*it] = pos++;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,k,j;
	clr(bit);
	cin>>n;
	fo(i, n)cin>>a[i];
	map<int, int> cnt;
	Fo(i, n-1, -1) valR[i] = 1+cnt[a[i]]++;
	cnt.clear();
	Fo(i, 0, n) valL[i] = 1+cnt[a[i]]++;
	suffix();
	ll ans = 0;
	fo(i,n){
		//since suffix stored as prefix
		//[1,x-1] represent ans for >x
		ans += query(id[valR[i]]-1);
		add(id[valL[i]]);
	}
	cout<<ans<<endl;
	return 0;
} 
