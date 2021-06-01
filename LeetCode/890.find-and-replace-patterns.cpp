class Solution {
    bool matches(string word, string pattern) {
        int n = word.size();
        vector<int> forward(26, -1), backward(26, -1);
        // map<char, char> forward, backward; unordered_map
        for(int i = 0; i < n; i++) {
            int x = word[i] - 'a', y = pattern[i] - 'a';
            // I am trying to map x to y
            if(forward[x] != -1 && forward[x] != y) return false;
            if(backward[y] != -1 && backward[y] != x) return false;
            forward[x] = y;
            backward[y] = x;
        }
        
        return true;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans = {};
        // O(n * k) k is avg word size
        for (auto word: words) {
            if (matches(word, pattern)) ans.push_back(word);
        }
        
        return ans;
    }
};

/* abb xyy yxx 

// abbccc 
// matches - xyyzzz yzzxxx
// does not match - xyyxxx

abbccc yzzxxx
abbccc xyyxxx

if a is mapped to y, then - 
    - a shall never be mapped to anything else
    - no other char shall be mapped to y
    
math background - 
1:1 mapping
*/