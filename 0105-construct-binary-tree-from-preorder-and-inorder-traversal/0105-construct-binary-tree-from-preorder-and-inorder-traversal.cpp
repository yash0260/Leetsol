class Solution {
public:
    
    TreeNode* build(vector<int>& preorder, int &preIndex, int left, int right,
                    unordered_map<int,int>& mp) {
        
        if(left > right) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int pos = mp[rootVal];

        root->left = build(preorder, preIndex, left, pos-1, mp);
        root->right = build(preorder, preIndex, pos+1, right, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        int preIndex = 0;

        return build(preorder, preIndex, 0, inorder.size()-1, mp);
    }
};