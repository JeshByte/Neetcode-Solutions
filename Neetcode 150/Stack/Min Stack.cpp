using ll=long long;
class MinStack {
public:
    stack<ll>st;
    ll mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(ll val) {
        if(st.empty()){
            mini=val;
            st.push(val);
            return;
        }
        if(val>=mini){
            st.push(val);
        }
        else{
            st.push(2*val-mini);
            mini=val;
        }
    }
    
    void pop() {
        if(st.top()>=mini){
            st.pop();
        }
        else{
            mini=2*mini-st.top();
            st.pop();
        }
    }
    
    ll top() {
        if(st.top()>=mini){
            return st.top();
        }
        else{
            return mini;
        }
    }
    
    ll getMin() {
        return mini;
    }
};
