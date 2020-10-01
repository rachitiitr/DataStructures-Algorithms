/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
     public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer>map =new HashMap<>();
        
        for(int i=0; i<nums.length; i++){
            map.put(nums[i],i);
        }
       for(int i=0; i<nums.length; i++){
           int diff = target - nums[i];
           if(map.containsKey(diff) && map.get(diff)!=i){
              return new int[] {i,map.get(diff)};
           }
       } 
     throw new IllegalArgumentException("No two sum solution");
    }
};
// @lc code=end

