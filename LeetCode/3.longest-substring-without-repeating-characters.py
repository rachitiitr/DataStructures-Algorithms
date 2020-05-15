class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0; // did you handle this?
        int n = s.size();
        int i(0), j(0);
        
        // s[j] is a char, 'A' is 65, 'a' is 97
        vector<int> cnt(300, 0); // ASCII length of 255 will be fine
        cnt[s[0]]++; // this can crash if string is empty
        
        int ans=1;
        while(j!=n-1){
            if(cnt[s[j+1]] == 0) {
                j++;
                cnt[s[j]] = 1;
                ans = max(ans, j-i+1);
            }
            else {
                i++;
                cnt[s[i]]--;
            }
        }
        return ans;
    }
};
