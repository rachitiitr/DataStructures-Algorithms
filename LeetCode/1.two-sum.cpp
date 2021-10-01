/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> id;
        for(int i = 0; i < nums.size(); i++) {
            int m = target - nums[i];
            if(id[m]) {
                return {id[m]-1, i};
            }
            id[nums[i]] = i+1;
        }
        return {-1, -1};
    }
};
// @lc code=end

