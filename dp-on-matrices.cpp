#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int n, m, a[N][N], dp[N][N], vis[N][N];

//Returns the max sum you can achieve 
//when you start at (i,j) and end at (n-1, m-1)
//and move only in down and right directions
int go(int i, int j){
    if(i == n-1 and j == m-1)
        return a[i][j];
    
    if(vis[i][j]) return dp[i][j];
    
    vis[i][j] = 1;
    
    int &ans = dp[i][j];
    
    if(i<n-1 and j<m-1)
        ans = a[i][j] + max(go(i, j+1), go(i+1, j));
    else if(i == n-1)
            ans = a[i][j]+ go(i, j+1);
    else 
        ans = a[i][j] + go(i+1, j);
    
	return ans;
}

int main() {
	int i, j;
	cin >> n >> m;
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			cin >> a[i][j];
			
	//Display the matrix
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
			
	//Print the answer
	cout << go(0, 0) << endl;
	//It should be 73 i.e 1+5+9+13+14+15+16
	
	
	return 0;
    
}

//Input:
//4 4
//1 2 3 4
//5 6 7 8
//9 10 11 12
//13 14 15 16
