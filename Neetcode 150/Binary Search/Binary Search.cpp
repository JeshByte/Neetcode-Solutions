class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ind=-1;
        int high=n-1,low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ind=mid;
                break;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ind;
    }
};
