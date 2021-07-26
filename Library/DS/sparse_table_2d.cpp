//2d sparse table for max
//0 based index
//LGN = 1 + lg2(N)
//LGM = 1 + lg2(M)

const int N = 1030;
const int M = 1030;
const int LGN = 11;
const int LGM = 11;

int a[N][M];
int dp[N][M][LGN][LGM];
const int MAXN = 2e6; //max(N, M)
int lg2[MAXN];
void pre(){
	//build lg2
	lg2[1] = log2(1);
	lg2[2] = log2(2);
	int val = 1, at = 4;
	int i;
	Fo(i, 3, MAXN){
		if (i == at){
			at *= 2;
			val++;
		}
		lg2[i] = log2(i);
	}
}
void build(int n, int m){
	pre();
	for(int i = 1; i <= n; ++ i) for(int j = 1; j <= m; ++ j) dp[i][j][0][0] = a[i-1][j-1];
	for(int j1 = 0; (1 << j1) <= n; ++ j1) {
		for(int j2 = 0; (1 << j2) <= m; ++ j2) if(j1 || j2) {
			for(int i1 = 1; i1 + (1 << j1) - 1 <= n; ++ i1) {
				for(int i2 = 1; i2 + (1 << j2) - 1 <= m; ++ i2) {
					if(j1) dp[i1][i2][j1][j2] = max(dp[i1][i2][j1 - 1][j2], dp[i1 + (1 << (j1 - 1))][i2][j1 - 1][j2]);
					else dp[i1][i2][j1][j2] = max(dp[i1][i2][j1][j2 - 1], dp[i1][i2 + (1 << (j2 - 1))][j1][j2 - 1]);
				}
			}
		}
	}
}

int query(int x1, int Y1, int x2, int y2){
	int k1 = lg2[x2-x1+1];
	int k2 = lg2[y2-Y1+1];
	return max(max(dp[x1][Y1][k1][k2], dp[x2 - (1 << k1) + 1][y2 - (1 << k2) + 1][k1][k2]),
			max(dp[x2 - (1 << k1) + 1][Y1][k1][k2], dp[x1][y2 - (1 << k2) + 1][k1][k2]));
}
