class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            if(nums[mid]>=nums[low]){
                if(nums[mid]>=target && target>=nums[low]){
                    high=mid-1; 
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return ans;
    }
};
