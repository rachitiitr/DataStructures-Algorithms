string vowels = "aeiou";
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, vector<int>> pref = {};
        for (char v: vowels) pref[v] = {0};
        
        for(char cur: s) {
            for(char v: vowels) {
                int last_parity = *pref[v].rbegin();
                if (cur == v) pref[v].push_back(1 - last_parity);
                else pref[v].push_back(last_parity);
            }
        }
        
        auto get_column = [&](int j) { // 1 based
            int id = 0;
            for(char v: vowels) {
                int x = pref[v][j];
                id = 2*id + x;
            }
            return id;
        };
        
        int rightmost[33];
        rightmost[0] = 0;
        for (int i = 1; i <= n; i++) {
            int id = get_column(i);
            rightmost[id] = i;
        }
   
        for (int i = 1; i <= n; i++) {
            // find the rightmost j substring(i, j) is valid
            // ith column
            int id = get_column(i-1);
            int j = rightmost[id];
            if (j < i) continue;
            ans = max(ans, j-i+1);
        }    
        return ans;
    }
};

/*
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
    i                 ^   ^
    maintain prefix count of all vowels pref[a][7] 
      a,b,a,e,e,a,e
          i   j
a - 0,1,1,0,0,0,1,1
e - 0,0,0,0,1,0,0,1
i - ...,1,.....,1
o - ...,0,.....,1
u - ...,0,.....,0
10100 <-- 20
n^2 substrings -> O(n) => overall O(n^3)
*/