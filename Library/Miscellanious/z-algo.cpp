//Z-Algorithm
//z[i] is length of prefix starting from i

// always pass stirng by reference, weird how it got me SIGSEGV in a Codechef problem
// https://codeforces.com/blog/entry/77906 
vector<int> go(const string &s){
	vector<int> z(s.size(), 0);
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

	return z;
}


// another implementation
template <typename T>
vector<int> z_function(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

template <typename T>
vector<int> z_function(const T &s) {
  return z_function((int) s.size(), s);
}

