
//  7 . link : [ https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array ]

#include<bits/stdc++.h>
using namespace std;
 
 int binarySearch(vector<int>& nums, int l,int r, int target){
        if(l>r){
            return -1;
        }
        int mid =  l+(r-l)/2;
        
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return binarySearch(nums,l,mid-1,target);
        else
            return binarySearch(nums,mid+1,r,target);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = binarySearch(nums,0,nums.size()-1, target);
        
        if(pos < 0)
            return {-1,-1};
        int left = pos;
        int right = pos;
        
        while(left > 0){
            if(nums[left-1] != target)
                break;
            left--;
        }
        while(right < nums.size()-1){
            if(nums[right+1] != target)
                break;
            right++;
        }
        
        return {left,right};
    }

/*
1
9
5 7 7 8 8 8 9 10 11
8


3 5
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

            int target ; cin >> target;

            vector<int> index =  searchRange(arr , target);
            cout << index[0] << " " << index[1] << endl;;     
        }


    return 0;    
}