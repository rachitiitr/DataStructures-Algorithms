
//  2. link : [ https://leetcode.com/problems/3sum ]

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
         int n = nums.size();
        set <vector<int>> s;
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++){
           
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                long long  sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                     s.insert({nums[i],nums[j],nums[k]});
                    j++; k--;
                }
                else if(sum < 0)
                    j++;
                else
                    k--;
            }
        }
        
         auto it = s.begin();
         while(it != s.end()){
            res.push_back(*it);
            it++;
         }
        return res;
}


/*
1
6
-1 0 2 -1 -4 1

-1 -1 2
-1 0 1
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

            vector<vector<int>> res =  threeSum(arr);
            for(int i=0; i<res.size(); i++){
                 for(int j=0; j<res[i].size(); j++)
                   cout << res[i][j] << " ";
               cout << endl;  
            }      
        }


    return 0;    
}