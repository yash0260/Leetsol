class Solution {
    int calculate(TreeNode* root,int &diameter){
    if(root==nullptr){
            return 0;
        }
        int lh=calculate(root->left,diameter);
        int rh=calculate(root->right,diameter);
            diameter = max(diameter, lh+rh);


       return 1+max(lh,rh);

    
}
    public:

    int diameterOfBinaryTree(TreeNode* root) {
            int diameter=0;
       calculate(root,diameter);
       return diameter;
    }


    

};