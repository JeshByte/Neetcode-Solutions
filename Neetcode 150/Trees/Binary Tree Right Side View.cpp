class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>ans;
        vector<int>temp;
        while(!q.empty()){
            TreeNode* pt=q.front();
            q.pop();
            if(pt==NULL){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            temp.push_back(pt->val);
            if(pt->left){
                q.push(pt->left);
            }
            if(pt->right){
                q.push(pt->right);
            }
        }
        vector<int>res;
        for(auto it:ans){
            res.push_back(it[it.size()-1]);
        }  
        return res;
    }
};
