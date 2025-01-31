class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int tp=0;
            while(!st.empty()){
                if(temperatures[st.top()]>temperatures[i]){
                    tp=st.top()-i;
                    break;
                }
                st.pop();
            }
            ans[i]=tp;
            st.push(i);
        }
        return ans;
    }
};
