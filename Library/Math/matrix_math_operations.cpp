struct matrix{
	int n, m;
	vector<vi> mat;
	matrix(){
		;
	}
	matrix(int x, int y = 0, int iden = 0){
		n = x; m = y;
		if(y==0) m = n;
		mat = vector<vi>(n, vi(m, 0));
		if(iden){
			int i;
			fo(i, n) mat[i][i] = 1;
		}
	}
	void out(){
		int i, j;
		fo(i, n){fo(j, m)cout<<mat[i][j]<<" ";cout<<endl;}
	}
	int rowsum(int x){
		int i;
		ll ans = 0;
		fo(i, m){
			ans += mat[x][i];
			if (ans>=mod) ans -= mod;
		}
		return ans;
	}
	int colsum(int x){
		int i;
		ll ans = 0;
		fo(i, n){
			ans += mat[i][x];
			if (ans>=mod) ans -= mod;
		}
		return ans;
	}
};
matrix operator *(matrix a, matrix b){
	matrix c = matrix(a.n);
	int i, j, k, n = c.n;
	fo(i, n)fo(j, n){
		int &val = c.mat[i][j];
		val = 0;
		fo(k, n){
			val += (a.mat[i][k]*1LL*b.mat[k][j])%mod;
			if (val >= mod) val -= mod;
		}
	}
	return c;
}
matrix operator *(int a, matrix b){
	matrix c = matrix(a.n);
	int i, j, k, n = c.n;
	fo(i, n)fo(j, n){
		int &val = c.mat[i][j];
		val = (a*b.mat[i][j])%mod;
	}
	return c;
}
matrix operator +(matrix a, matrix b){
	matrix c = matrix(a.n);
	int i, j, k, n = c.n;
	fo(i, n)fo(j, n){
		int &val = c.mat[i][j];
		val = (a.mat[i][j]+b.mat[i][j]);
		if (val >= mod) val -= mod;
	}
	return c;
}
matrix operator -(matrix a, matrix b){
	matrix c = matrix(a.n);
	int i, j, k, n = c.n;
	fo(i, n)fo(j, n){
		int &val = c.mat[i][j];
		val = (a.mat[i][j]-b.mat[i][j]);
		if (val >= mod) val -= mod;
		if (val < 0) val += mod;
	}
	return c;
}
matrix operator %(matrix M, int MOD)
{
	matrix temp(M.n);
	for(int i=0;i<M.n;i++)
		for(int j=0;j<M.n;j++)
			temp.mat[i][j]=M.mat[i][j]%MOD;
	return temp;
}
matrix p(matrix &n,int m,int MOD = mod)
{
    if(m==0) 
		return matrix(n.n,n.n, 1);
    matrix x=p(n,m/2,MOD);
    if(m%2==0) 
       return x*x;
    else
       return x*x*n;
}
