class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            correctPos = nums[i]-1 # number 3 goes to index 2
            while 1 <= nums[i] <= n and nums[i] != nums[correctPos]:
                nums[i], nums[correctPos] = nums[correctPos], nums[i]
                correctPos = nums[i]-1 # now nums[i] has changed
                
        
        for i in range(n):
            if i+1 != nums[i]:
                return i+1
        return n+1
