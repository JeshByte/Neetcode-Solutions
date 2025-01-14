class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1){
            return 0;
        }
        int i=0,j=1;
        int ans=0;
        while(j<n){
            if(prices[i]>=prices[j]){
                i=j;
                j++;
            }
            else{
                int profit=prices[j]-prices[i];
                ans=max(ans,profit);
                j++;
            }
        }
        return ans;
    }
};
