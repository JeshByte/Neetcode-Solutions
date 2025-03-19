using ll=long long;
class Solution {
public:
    bool check(TreeNode* root,ll low,ll high){
        if(root==NULL){
            return true;
        }
        if(low<root->val && root->val<high){
            return check(root->left,low,root->val) && check(root->right,root->val,high);
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        ll high=LLONG_MAX;
        ll low=LLONG_MIN;
        return check(root,low,high);
    }
};
