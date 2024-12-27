class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        int n=strs.size();
        for(int i=0;i<n;i++){
            res+=to_string(strs[i].size())+"#"+strs[i];
        }
        //cout<<res<<'\n';
        return res;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        int len=s.size();
        while(i<len){
            int j=i;
            string tp="";
            while(s[j]!='#'){
                tp+=string(1,s[j]);
                j++;
            }
            int req_len=stoi(tp);
            i=j+1;
            //cout<<req_len<<'\n';
            ans.push_back(s.substr(i,req_len));
            i=i+req_len;
        }
        return ans;
    }
};
