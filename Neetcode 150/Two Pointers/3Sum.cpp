class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<n;i++){
            int target=0-nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                int total=nums[j]+nums[k];
                if(total==target){
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(total>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<int>>res;
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};
