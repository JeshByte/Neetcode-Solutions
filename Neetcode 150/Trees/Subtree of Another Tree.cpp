class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL && q!=NULL){
            return false;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        return true && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        bool check = isSameTree(root,subRoot);
        if(check){
            return true;
        }
        else{
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
    }
};
