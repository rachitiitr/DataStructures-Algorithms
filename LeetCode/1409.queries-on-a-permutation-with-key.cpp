class Solution {
   public:
    vector<int> processQueries(vector<int>& queries, int m)
    {
        vector<int> ans, P(m);
        int n = queries.size();
        iota(P.begin(), P.end(), 1);  //  initialize P
        for (int i = 0; i < n; i++) {
            auto it = find(P.begin(), P.end(), queries[i]);  //  find location of query in P
            ans.push_back(it - P.begin());                   //  push index of the query in ans vector
            rotate(P.begin(), it, it + 1);                   //  move the query at the beginning of P
        }
        return ans;
    }
};