class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cur = 0;
            // considering the suffix from pos i
            // [arr[i], arr[i+1], ... arr[n-1]]
               // 1         2              
            for(int j = i; j < n; j++) {
                cur += (j-i+1) * arr[j];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};

/*
a1 <= a2 <= a3 .... // we have proved
(a1,a2,...,ak) <-- reordering of satisfaction array + you can remove elements
max(a1 + 2*a2 + 3*a3 + k*ak)
    
    -9   -8  -1   0   5
    
    how long a prefix would you remove to get the max score
*/
