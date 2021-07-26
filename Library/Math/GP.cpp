class GP{
	ll a, r;
	public:
	GP() {}
	
	GP(ll x, ll y){ a=x%mod, r = y%mod; }
	void init(ll x, ll y){ a=x%mod, r = y%mod; }
	ll sum(ll lo, ll hi){
		return prefix(hi)-prefix(lo-1);
	}
	ll nth(ll n){
		return a*mpow(r, n-1)%mod;
	}
	ll prefix(ll n){
		if(n==0) return 0;
		if(r==1) return n*a;
		// a * (r^n - 1) / (r - 1)
		ll ans = (a * (mpow(r, n)-1+mod) ) % mod;
		ans *= mpow(r-1, mod-2);
		ans %= mod;
		return ans;
	}
};

