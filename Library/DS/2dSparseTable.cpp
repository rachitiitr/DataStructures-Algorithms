//second file is better
//ye codechef wala submission h mera
const int  N =  1003;
int a[N][N], dp[N][N][10][10];
const int lg = 10;
//lg is 1 power greater than N
ll dpp[N][N]; 
 
int st[N];
int max(int a, int b, int c, int d){
	return max(a, max(b, max(c, d)));
}
int n, m;
void mem(){
	int i,j,x,y,k;
	   st[1] = 0;
        int c = 0;
        Fo(i, 2, N)
        {
                int v = (1 << c);
                if (v + v < i)
                        c++;
                st[i] = c;
        }
	fo(i, n)
	fo(j, m)
		dp[i][j][0][0] = a[i][j];
		
	Fo(i, 0, n)
        {
                Fo(k, 1, lg)
                {
                        int val = (1 << k);
                        int nval = val / 2;
                        Fo(j, 0, m)
                        {
                                if (j + val > m)
                                        break;
                                dp[i][j][k][0] = max(dp[i][j][k - 1][0], dp[i][j + nval][k - 1][0]);
                        }
                }
        }
        Fo(j, 0, m)
        {
                Fo(k, 1, lg)
                {
                        int val = (1 << k);
                        int nval = val / 2;
                        Fo(i, 0, n)
                        {
                                if (i + val > n)
                                        break;
                                dp[i][j][0][k] = max(dp[i][j][0][k - 1], dp[i + nval][j][0][k - 1]);
                        }
                }
        }
      int k1,k2,st2;
      
      int st1=st2=lg-1;
      
	 Fo(k1, 1, st1 + 1)
        {
                int val1 = (1 << k1);
                int nval1 = val1 / 2;
                Fo(k2, 1, st2 + 1)
                {
                        int val2 = (1 << k2);
                        int nval2 = val2 / 2;
                        Fo(i, 0, n)
                        {
                                Fo(j, 0, m)
                                {
                                        if ((j + val1 > m) || (i + val2 > n))
                                                continue;
                                                
                                        dp[i][j][k1][k2] = max(dp[i][j][k1 - 1][k2 - 1], dp[i + nval2][j][k1 - 1][k2 - 1], dp[i][j+nval1][k1 - 1][k2 - 1], dp[i + nval2][j+nval1][k1 - 1][k2 - 1]);
                                }
                        }
                }
        }
        
}
 
int query(int i, int j, int down, int k){
	int dx = down - i + 1;
    int dy = k - j + 1;
    int k1 = st[dy];
    int k2 = st[dx];
    int val1 = (1 << k1);
    int val2 = (1 << k2);
	 int dp1 = max(dp[i][j][k1][k2], dp[i][k-val1+1][k1][k2]);
	 int dp2 = max(dp[down - val2 + 1][j][k1][k2], dp[down - val2 + 1][k - val1 + 1][k1][k2]);
	return max(dp1,dp2);
	
}
