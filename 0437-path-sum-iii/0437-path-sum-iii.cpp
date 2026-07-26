/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<long long, int> prefix;
    int ans = 0;
    void dfs(TreeNode* root, long long currsum, int target) {
        if (!root)
            return;
        currsum += root->val;
        if (prefix.count(currsum - target))
            ans += prefix[currsum - target];
        prefix[currsum]++;
        dfs(root->left, currsum, target);
        dfs(root->right, currsum, target);
        prefix[currsum]--;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
    }
};