using interval = vector<int>; // length 2
// [1, 3] and [1, 19]
// [1, 19] can contain [1, 3]
bool comparator(const interval &left, const interval &right) {
    if(left[0] == right[0])
        return left[1] > right[1];
    return left[0] < right[0]; // asc order of starting time
}

class Solution {
public:
    int removeCoveredIntervals(vector<interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        int ans = intervals.size();
        
        int maxEnd = 0;

        for(interval cur: intervals) {
            // need to check if cur is already contained
            int curEnd = cur[1];
            if (curEnd <= maxEnd) {
                ans--; // throw away the current interval
            }
            
            maxEnd = max(maxEnd, curEnd);
        }
        
        return ans;
    }
};
