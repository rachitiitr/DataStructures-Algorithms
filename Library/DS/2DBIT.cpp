const int N = 305, M = 305;
class BIT_2D{
	int bit[N][M];
	int inf;
	public:
		BIT_2D(){
			inf = 1e9;
			int i, j;
			fo(i, N) fo(j, M) bit[i][j] = inf;
		}
		int f(int x){
			return x&(-x);
		}
		void add(int x, int y, int val){
			int Y = y;
			while(x <= N){
				y = Y;
				while(y <= M){
					bit[x][y] = min(bit[x][y], val);
					y += f(y);
				}
				x += f(x);
			}
		}
		int get(int x, int y){
			int Y = y;
			int ans = mod;
			while(x){
				y = Y;
				while(y){
					ans = min(bit[x][y], ans);
					y -= f(y);
				}
				x -= f(x);
			}
			return ans;
		}
		void clear(int x, int y){
			int Y = y;
			while(x <= N){
				y = Y;
				while(y <= M){
					bit[x][y] = inf;
					y += f(y);
				}
				x += f(x);
			}
		}
	
};
