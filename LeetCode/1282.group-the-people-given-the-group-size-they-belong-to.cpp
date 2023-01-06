class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> peopleInGroupSize = {};
        for(int i = 0; i < n; i++) {
            int curSize = groupSizes[i];
            peopleInGroupSize[curSize].push_back(i);
        }
        vector<vector<int>> ans = {};
        for(auto [groupSize, people]: peopleInGroupSize) {
            // start making groups of |groupSize|
            vector<int> cur = {};
            for(int i = 0; i < people.size(); i++) {
                cur.push_back(people[i]);
                if ( cur.size() == groupSize) {
                    ans.push_back(cur);
                    cur = {};
                }
            }
        }
        return ans;
    }
};
/*
[group_size] --> [ids of people in it]
[3] --> [0,1,2,3,4,6]
[1] --> [5]
    */