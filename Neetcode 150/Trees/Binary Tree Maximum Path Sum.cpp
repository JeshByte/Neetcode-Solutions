class Solution {
public:
    int solve(TreeNode* root,int& mx){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left,mx);
        int r=solve(root->right,mx);
        mx=max(mx,root->val+l+r);
        mx=max(mx,root->val+l);
        mx=max(mx,root->val+r);
        mx=max(mx,root->val);
        return max(root->val,max(root->val+l,root->val+r));
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        solve(root,mx);
        return mx;
    }
};
