class Solution {
public:
    bool isGood(vector<int>& piles,int h,int mid,int n){
        int time=0;
        for(int i=0;i<n;i++){
            time+=((piles[i]+mid-1)/mid);
            if(time>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isGood(piles,h,mid,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
