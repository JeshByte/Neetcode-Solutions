class Solution {
public:
    int findPos(vector<int>& inorder,int val,int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preInd, int inSind,int inEind,int n){
        if(preInd>=n || inSind>inEind){
            return NULL;
        }
        int val=preorder[preInd++];
        TreeNode* root=new TreeNode(val);
        int pos=findPos(inorder,val,n);
        root->left=solve(preorder,inorder,preInd,inSind,pos-1,n);
        root->right=solve(preorder,inorder,preInd,pos+1,inEind,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l=inorder.size();
        int preInd=0;
        TreeNode* root=solve(preorder,inorder,preInd,0,l-1,preorder.size());
        return root;
    }
};
