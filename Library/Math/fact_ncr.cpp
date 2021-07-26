const int N = 1e6;
ll fac[N], inv[N], b[N];
void pre(){
	int i;
	fac[0] = inv[0] = 1;
	fac[1] = inv[1] = 1;
	Fo(i, 2, N){
		fac[i] = (i*fac[i-1])%mod;
		inv[i] = (mpow(i, mod-2)*inv[i-1])%mod;
	}
}
ll C(int n, int r){
	if (r>n)return 0;
	ll ans = fac[n];
	ans *= inv[r];
	ans %= mod;
	ans *= inv[n-r];
	ans %= mod;
	return ans;
}
