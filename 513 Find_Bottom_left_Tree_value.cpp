/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        while(!que.empty()){
            int size = que.size();
            vector<int> row;
            for(int i=0;i<size;i++){
                TreeNode *front = que.front();
                que.pop();
                row.push_back(front->val);
                if(front->left!=NULL){
                    que.push(front->left);
                }
                if(front->right!=NULL){
                    que.push(front->right);
                }
            }
            res.push_back(row);
        }
        return res[res.size()-1][0];
    }
};
