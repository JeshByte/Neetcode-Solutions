class Solution {
public:
    void inorder(TreeNode* root,vector<int>&path){
        if(root!=NULL){
            inorder(root->left,path);
            path.push_back(root->val);
            inorder(root->right,path);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>path;
        inorder(root,path);
        return path[k-1];
    }
};
