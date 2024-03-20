
//  5. link : [ https://leetcode.com/problems/trapping-rain-water ]

#include<bits/stdc++.h>
using namespace std;


int trap(vector<int>& height) {
       int n = height.size();
        if(n<=2)
            return 0;
        
        int left[n];
        int right[n];
        
        left[0] = height[0];
        for(int i=1; i<n; i++)
          left[i] = max(left[i-1],height[i]);
        
        right[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--)
            right[i] = max(right[i+1],height[i]);
        
        int water=0;
        for(int i=0; i<n; i++){
            water += min(left[i],right[i])-height[i];
        }
        return water;
}

/*
1
12
0 1 0 2 1 0 1 3 2 1 2 1

6

*/

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

        int test;
        cin >> test;

        while(test--){
            int n; 
            cin >> n;
            vector<int> arr(n);
            for(int i=0; i<n; i++)
                 cin >> arr[i];

            cout << trap(arr) << endl;;     
        }


    return 0;    
}