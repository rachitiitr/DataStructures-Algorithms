#include<iostream>
#include<vector>

using namespace std;


int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cout << "Case #" << i+1 << ": ";

		string s;
		cin >> s;

		int n = s.size();
		
		vector<int> other(n, 0);

		for(int j = 0; j < n; j++) {
			if(s[j] == '4') s[j] = '3', other[j] = 1;
		}

		cout << s << " " ;
		

		int j;
		for(j = 0; other[j] == 0 and j < n; j++);
		for(; j < n; j++) cout << other[j];
		cout << endl;


	}

	return 0;
}
