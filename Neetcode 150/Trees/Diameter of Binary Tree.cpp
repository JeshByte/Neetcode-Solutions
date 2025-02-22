class Solution {
public:
    pair<int,int> solve(TreeNode* root,int& diameter){
        if(root==NULL){
            return {-1,-1};
        }
        pair<int,int> left=solve(root->left,diameter);
        pair<int,int> right=solve(root->right,diameter);
        pair<int,int> ans={0,0};
        int left_max=max(left.first,left.second);
        int right_max=max(right.first,right.second);
        ans.first=1+left_max;
        ans.second=1+right_max;
        diameter=max(diameter,ans.first+ans.second);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=-1;
        solve(root,diameter);
        return diameter;
    }
};
