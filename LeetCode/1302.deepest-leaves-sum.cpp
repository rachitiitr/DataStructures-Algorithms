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
    pair<int, int> getDepthAndSum(TreeNode* root) {
        if (root == NULL) return {0, 0};
        if (root->left == NULL and root->right == NULL)
            return {1, root->val};
        
        auto [left_depth, left_sum] = getDepthAndSum(root->left);
        auto [right_depth, right_sum] = getDepthAndSum(root->right);
        
        if (left_depth == right_depth)
            return {1 + left_depth, left_sum + right_sum};
        if (left_depth > right_depth)
            return {1 + left_depth, left_sum};
        return {1 + right_depth, right_sum};
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        return getDepthAndSum(root).second;
    }
};