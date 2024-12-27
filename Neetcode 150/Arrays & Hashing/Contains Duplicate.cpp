class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>m1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m1[nums[i]]++;
            if(m1[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};
