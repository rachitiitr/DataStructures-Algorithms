#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, j, tt, n, f, F;
	char p;
	cin >> tt >> F;
	while(tt--) {
		map<string, int> cnt;
		map<string, int> pos;
		cnt.clear();
		pos.clear();
		
		f = F;
		//1 to 595 abcde,badce,
		//ask first three chars of 119 nos //357
		vector<string> my(119, "");
		for(i=0; i<119; i++){
			my[i] = "";
			int x = (i*5)+1;
			cout << x << "\n" << flush;
			cin >> p;
			my[i] += p;
			
			cout << x+1 << "\n" << flush;
			cin >> p;
			my[i] += p;
			
			cout << x+2 << "\n" << flush;
			cin >> p;
			my[i] += p;
			
			cnt[my[i]]++;
			pos[my[i]] = i;
		}
		int cx = 0;
		for(i=0; i<119; i++) if(cnt[my[i]] == 1) cx = i;
		
		int ign = 0;
		if(cx == ign) ign = 1;
		
		string ans = my[cx];
		i = cx;
		int x = (i*5)+4;
		cout << x << "\n" << flush;
		cin >> p;
		my[i] += p;
		
		set<char> xx = {'A', 'B', 'C', 'D', 'E'};
		for(char cc: my[cx]) xx.erase(cc);
		char fin = *xx.begin();
		ans = ans + fin + p;
		cout << ans << "\n" << flush;
		cin >> p;
		if(p != 'Y') exit(0);
		
	}
	return 0;
}
