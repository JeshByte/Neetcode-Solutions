class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>res;
        for(auto it:mp){
            res.push({it.second,it.first});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            pair<int,int>tp=res.top();
            res.pop();
            ans.push_back(tp.second);
        }
        return ans;
    }
};
