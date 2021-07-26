ll tem[N][N],res[N][N];
void matpow(ll g[N][N], int ex){
	int i, j, k;
	if (ex == 1) return ;
	fo(i, x) fo(j, x) tem[i][j] = g[i][j];	
	matpow(g, ex/2);
	fo(i, x) fo(j, x) { res[i][j] = 0; fo(k, x) res[i][j] += g[i][k]*g[k][j]%mod;}
	fo(i, x) fo(j, x) res[i][j] %= mod;
	if (ex&1){
		fo(i, x) fo(j, x) { g[i][j] = 0; fo(k, x) g[i][j] += res[i][k]*tem[k][j]%mod;}
		fo(i, x) fo(j, x) g[i][j] %= mod;
	}
	else
		fo(i, x) fo(j, x) g[i][j] = res[i][j];
}
