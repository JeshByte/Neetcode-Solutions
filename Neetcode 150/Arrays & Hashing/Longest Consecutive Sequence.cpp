class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        if(n<=1){
            return n;
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-1)!=mp.end()){
                mp[nums[i]]=0;
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==1){
                int j=0,co=0;
                while(mp.find(nums[i]+j)!=mp.end()){
                    j++;
                    co++;
                }
                ans=max(ans,co);
            }
        }
        return ans;
    }
};
