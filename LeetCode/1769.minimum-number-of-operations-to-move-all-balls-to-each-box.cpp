class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int left_cnt = 0, tot_cnt = 0; // cnt of 1s
        int left_sum = 0, tot_sum = 0; // sum of indices where its a 1
        
        
        for(int i = 0; i < n; i++) {
            if (boxes[i] == '1') tot_cnt++, tot_sum += i;    
        }
        
        vector<int> ans = {};
        for(int i = 0; i < n; i++) {
            int right_cnt = tot_cnt - left_cnt;
            int right_sum = tot_sum - left_sum;
            
            int left = left_cnt * i - left_sum;
            int right = right_sum - right_cnt * i;
            ans.push_back(left + right);
            
            if (boxes[i] == '1') left_cnt++, left_sum += i;
        }  
        return ans;
    }
};


/*
i=13
j<13
i-j1 + i-j2 => 2*i - (j1+j2)

j>13
j1-i + j2-i => (j1+j2) - 2 *(i)
*/

