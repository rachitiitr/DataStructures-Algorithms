ll a[N], dp[N];
const ll inf = 1e16;
void slide(vi &A, int b){
	//dp[i] = max(A[i], ... , A[i+k-1])
	int n = A.size();
	deque<pii> win;
	int i;
	//move from left to right
	//initialse window [0, b-1]
	fo(i, b){
		while(!win.empty() and win.back().F <= A[i]) win.pop_back();
		win.pb({A[i], i});
	}
	fo(i, n){
		dp[i] = win.front().F;
		int x = i+b;
		if(x<n) {
			while(!win.empty() and win.back().F <= A[x]) win.pop_back();
			win.pb({A[x], x});
		}
		while(!win.empty() and win.front().S <= i) win.pop_front();
		//if [i, i+b-1] doesnt exits => - inf
		if(i+b-1 >= n) dp[i] = -inf;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	cin >> n;
	vi A;
	A.resize(n, 0);
	fo(i, n) cin >> A[i];
	slide(A, 3);
	fo(i, n) cout << dp[i] << " " ;
	return 0;
} 
