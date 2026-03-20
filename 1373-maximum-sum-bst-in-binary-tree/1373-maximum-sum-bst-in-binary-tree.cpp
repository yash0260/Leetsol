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
    int maxSum = 0;

    struct NodeValue {
        int minNode, maxNode, sum;
        bool isBST;

        NodeValue(int minNode, int maxNode, int sum, bool isBST) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->sum = sum;
            this->isBST = isBST;
        }
    };

    NodeValue helper(TreeNode* root) {
        // Base case
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check BST condition
        if (left.isBST && right.isBST &&
            left.maxNode < root->val && root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;

            // Update answer
            maxSum = max(maxSum, currSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum,
                true
            );
        }

        // Not a BST
        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};