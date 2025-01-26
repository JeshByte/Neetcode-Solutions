class Solution {
public:
    vector<int> nextSmallest(vector<int>& heights, int n){
        stack<pair<int,int>>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int tp=n;
            while(!st.empty()){
                if(st.top().first<heights[i]){
                    tp=st.top().second;
                    break;
                }
                st.pop();
            }
            ans[i]=tp;
            st.push({heights[i],i});
        }
        return ans;
    }
    vector<int> prevSmallest(vector<int>& heights, int n){
        stack<pair<int,int>>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int tp=-1;
            while(!st.empty()){
                if(st.top().first<heights[i]){
                    tp=st.top().second;
                    break;
                }
                st.pop();
            }
            ans[i]=tp;
            st.push({heights[i],i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next=nextSmallest(heights,n);
        vector<int>prev=prevSmallest(heights,n);
        int ans=-1;
        for(int i=0;i<n;i++){
            int width=next[i]-prev[i]-1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
    }
};
