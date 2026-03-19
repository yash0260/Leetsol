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
    void f(vector<int>&arr,TreeNode*root){
        if(root==nullptr){
            return ;
        }
        arr.push_back(root->val);
        f(arr,root->left);
        f(arr,root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
     vector<int>arr;

     f(arr,root); 
     unordered_set<int>ans;
     for(int i=0;i<arr.size();i++){
        ans.insert(arr[i]);
     }  
     for(int i=0;i<arr.size();i++){
       if(ans.find(k-arr[i])!=ans.end() && 2*arr[i]!=k){

        return true;
       }
        
     }
     return false;
    }
};