class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n=nums.size();
        int i=0,j=0;
        vector<int>res;
        while(j<n){
            while(!dq.empty() && nums[j]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(j-i+1<k){
                j++;
                continue;
            }
            res.push_back(nums[dq.front()]);
            i++;
            j++;
            while(!dq.empty() && dq.front()<(j+1-k)){
                dq.pop_front();
            }
        }
        return res;
    }
};
