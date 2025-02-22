class Solution {
public:
    pair<int,bool> solve(TreeNode* root){
        if(root==NULL){
            return {0,true};
        }
        pair<int,bool> left=solve(root->left);
        pair<int,bool> right=solve(root->right);
        pair<int,bool> ans={0,false};
        ans.first=max(left.first,right.first)+1;
        if(left.second && right.second && abs(left.first-right.first)<=1){
            ans.second=true;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};
