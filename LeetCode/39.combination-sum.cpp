using choice = vector<int>;
vector<int> arr = {};

// returning all possible choices to make target sum by using suffix of array [curIndex, ...]
vector<choice> getAllChoices(int curIndex, int target) {
    // base case
    if(target < 0) return {}; // no valid choice
    if(target == 0) return {{}}; // one choice, and you chose nothing
    if(curIndex == arr.size()) return {};
    
    int curNumber = arr[curIndex];
    
    vector<choice> ans = getAllChoices(curIndex+1, target); // curNumber is not used at all
    
    vector<choice> other = getAllChoices(curIndex, target - curNumber); // using it once
    for(choice c: other) {
        c.push_back(curNumber);
        // now c is a valid choice 
        ans.push_back(c);
    }
    
    return ans;
}

class Solution {
    
public:
    vector<choice> combinationSum(vector<int>& candidates, int target) {
        arr = candidates;
        return getAllChoices(0, target);
    }
};
