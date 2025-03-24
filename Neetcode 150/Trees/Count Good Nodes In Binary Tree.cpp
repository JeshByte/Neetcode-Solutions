class Solution {
public:
    void solve(TreeNode* root,int mx,int &ans){
        if(root==NULL){
            return;
        }
        if(root->val>=mx){
            ans++;
        }
        mx=max(mx,root->val);
        solve(root->left,mx,ans);
        solve(root->right,mx,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        solve(root,INT_MIN,ans);
        return ans;
    }
};
