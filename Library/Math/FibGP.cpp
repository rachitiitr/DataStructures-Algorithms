//http://codeforces.com/blog/entry/13036
ll A = 276601605;
ll C = 691504013;
ll D = 308495997;
class Fib{
	GP gp, gp2;
	//fn = A*(C^N-D^N)
	public:
	Fib() {init();}
	void init(){
		gp.init(A*C, C);
		gp2.init(A*D, D);
	}
	ll nth(ll n){
		return (gp.nth(n)-gp2.nth(n)+mod)%mod;
	}
	ll sum(ll lo, ll hi){
		return (prefix(hi) - prefix(lo-1) + mod)%mod;
	}
	ll prefix(ll n){
		if(n==0) return 0;
		return (gp.prefix(n)-gp2.prefix(n)+mod)%mod;
	}
};
