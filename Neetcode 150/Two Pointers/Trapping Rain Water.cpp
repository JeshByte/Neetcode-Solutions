class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int max_i=height[i],max_j=height[j];
        int ans=0;
        while(i<j){
            if(max_i<=max_j){
                i++;
                if(max_i>height[i]){
                ans+=max_i-height[i];
                }
                max_i=max(max_i,height[i]);
            }
            else{
                j--;
                if(max_j>height[j]){
                ans+=max_j-height[j];
                }
                max_j=max(max_j,height[j]);
            }
        }
        return ans;
    }
};
