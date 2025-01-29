class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            int len=tokens[i].size();
            if(isdigit(tokens[i][len-1])){
                st.push(stoi(tokens[i]));
            }
            else{
                int val2=st.top();
                st.pop();
                int val1=st.top();
                st.pop();
                int ans;
                if(tokens[i][0]=='+'){
                    ans=val1+val2;
                }
                else if(tokens[i][0]=='-'){
                    ans=val1-val2;
                }
                else if(tokens[i][0]=='*'){
                    ans=val1*val2;
                }
                else{
                    ans=val1/val2;
                }
                st.push(ans);
            }
        }
        int ans=st.top();
        return ans;
    }
};
