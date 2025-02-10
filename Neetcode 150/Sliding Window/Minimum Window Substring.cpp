class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        map<char,int>mpt,mps;
        int need=0,have=0;
        for(int i=0;i<m;i++){
            mpt[t[i]]++;
        }
        need+=mpt.size();
        int i=0,j=0;
        int min_len=1e6;
        int start=-1,end=-1;
        while(j<n){
            if(mpt.find(s[j])!=mpt.end()){
                mps[s[j]]++;
                if(mps[s[j]]==mpt[s[j]]){
                    have++;
                }
            }
            if(have==need){
                if((j-i+1)<min_len){
                    start=i;
                    end=j;
                    min_len=(j-i+1);
                    //cout<<start<<" "<<end<<'\n';
                }
                while(have==need){
                    if(mpt.find(s[i])!=mpt.end()){
                        mps[s[i]]--;
                        if(mps[s[i]]<mpt[s[i]]){
                            have--;
                        }
                    }
                    i++;
                     if(have==need){
                            if((j-i+1)<min_len){
                                start=i;
                                end=j;
                                min_len=(j-i+1);
                                //cout<<start<<" "<<end<<'\n';
                            }
                        }                    
                }
            }
            j++;
        }
        string ans="";
        if(start==-1){
            return ans;
        }
        for(int i=start;i<=end;i++){
            ans+=string(1,s[i]);
        }
        return ans;
    }
};
