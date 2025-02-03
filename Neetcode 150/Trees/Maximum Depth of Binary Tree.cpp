class Solution {
public:
    void solve(TreeNode* root,int cnt,int& ma){
        if(root==NULL){
            ma=max(ma,cnt);
            return;
        }
        cnt++;
        solve(root->left,cnt,ma);
        solve(root->right,cnt,ma);
    }
    int maxDepth(TreeNode* root) {
        int ma=-1;
        solve(root,0,ma);
        return ma;
    }
};
