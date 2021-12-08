class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Use a typical implementation of BFS with a queue

        queue<string> que1;
        que1.push(beginWord);
        int dist=0;

        while(!que1.empty()) {
            dist+=1;
            int l=que1.size();
            for(int i=0; i<l; ++i) {
                for(vector<string>::iterator itr=wordList.begin(); itr!=wordList.end(); ++itr) {
                    int d=wordDist(que1.front(), *itr);
                    if(d>1) continue;
                    if(endWord.compare(*itr)==0) return dist+1;
                    que1.push(*itr);
                    wordList.erase(itr);
                    --itr;
                }
                que1.pop();
            }
        }

        return 0;
    }

private:
    //A function for computing distance between words
    int wordDist(string s1, string s2) {
        int n=min(s1.length(), s2.length());
        int dist=0;

        for(int i=0; i<n; ++i)
            if(s1[i]!=s2[i]) dist+=1;

        return dist;
    }
};
