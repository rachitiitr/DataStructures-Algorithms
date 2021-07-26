// Check Youtube video for video explanation
class Solution {
public:
    int firstMissingPositive(vector<int> A)
    {
        int n = A.size();
        for(int i = 0; i < n; ++ i) {
            while(A[i] >= 1 && A[i] <= n && A[i] != A[A[i]-1])
                swap(A[i], A[A[i] - 1]);
        }
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};
