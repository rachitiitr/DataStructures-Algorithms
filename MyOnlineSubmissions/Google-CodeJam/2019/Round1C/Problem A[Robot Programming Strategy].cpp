//Problem Link: https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134c90
#include <bits/stdc++.h>
using namespace std;
const char R = 'R';
const char P = 'P';
const char S = 'S';
map<char,char> win, l;

char M[300][603];
int len[300], ign[300];
char winner(set<char> a)
{
	char x = *a.begin();
	char y = *a.rbegin();
	string z = ""; z += x; z += y;
	if (z == "PR") return R;
	if (z == "PS") return P;
	if (z == "RS") return S;
}

int main() {
	win[R]=P;
	win[P]=S;
	win[S]=R;
	
	l[R]=S;
	l[P]=R;
	l[S]=P;
	ios_base::sync_with_stdio(0);
	int t, i, j, nj, n;
	string s;
	cin >> t;
	int T = t;
	while(t--) {
		for(i=0; i < 300; i++) len[i] = ign[i] = 0;
		cout << "Case #" << T-t << ": ";
		cin >> n;
		int mxl = 0;
		for(i = 0; i < n; i++) {
			cin >> s;
			len[i] = s.length(); len[i] = min(len[i], 500);
			mxl = max(mxl, len[i]); mxl = min(mxl, 500);
			
			for(j = 0; j < 500; j++) {
				nj = j%len[i];
				M[i][j] = s[nj];
			}
		}
		
		int flag = 0;int count = 0;
		string ans = "";
		for( j = 0; j < 500; j++) {
			set<char> choices = {R, P, S};
			set<char> want = {};	
			for( i = 0; i < n; i++) {
				if(ign[i]) continue;
				char c = M[i][j];
				choices.erase(l[c]);
				want.insert(win[c]);
			}
			if(choices.empty() or want.size() == 3) {
				flag = -1; //IMPOSSIBLE
				break;
			}
			if(want.size() == 0) {
				flag = 1; // WE WON
				break;
			}
			if(want.size() == 1) {
				flag = 1; // WE WON
				ans += *want.begin();
				break;
			}
			//want 2
			char chala = winner(want);
			ans += chala;
			for( i = 0; i < n; i++) {
				if(l[chala] == M[i][j]) ign[i] = 1;
			}
		}
		
		for(i = 0; i < n; i++) if(ign[i] == 1) count++;
		if(count == n) flag = 1;
		if(flag == -1) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";
	}
	
	return 0;
}
