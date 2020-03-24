//Z-Algorithm
//z[i] is length of prefix starting from i
int z[N];
void go(string s){
	int i, n = s.size(), L = 0, R = 0;
	z[0] = 0;
	Fo(i, 1, n){
		if (i > R){
			L = R = i;
			while(R<n and s[R] == s[R-L]) R++;
			R--;
			z[i] = R-L+1;
		}
		else{
			int k = i-L;
			if (z[k] < R-i+1) z[i] = z[k];
			else{
				L = i;
				while(R<n and s[R] == s[R-L]) R++;
				R--;
				z[i] = R-L+1;
			}
		}
	}
	
}
