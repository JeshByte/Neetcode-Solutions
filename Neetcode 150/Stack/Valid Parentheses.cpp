class Solution {
public:
    char findComp(char c){
        char comp;
        if(c==')'){
            comp='(';
        }
        else if(c==']'){
            comp='[';
        }
        else{
            comp='{';
        }
        return comp;
    }
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                char comp=findComp(s[i]);
                if(!st.empty() && st.top()==comp){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
