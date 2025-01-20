class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=0,f=0;
        int n=nums.size();
        while(1){
            s=nums[s];
            f=nums[nums[f]];
            if(s==f){
                break;
            }
        }
        f=0;
        while(1){
            f=nums[f];
            s=nums[s];
            if(s==f){
                return s;
            }
        }
        return 0;
    }
};
