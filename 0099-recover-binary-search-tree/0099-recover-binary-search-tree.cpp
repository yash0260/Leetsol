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
void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>nodes;
        inorder(root,nodes);
        vector<int>values;
        for(auto node:nodes){
            values.push_back(node->val);
        } 
        sort(values.begin(),values.end());
        for(int i=0;i<nodes.size();i++){
            nodes[i]->val=values[i];
        }

    }
};