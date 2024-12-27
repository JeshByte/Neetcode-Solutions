class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        if(n!=t.size()){
            return false;
        }
        map<int,int>m1;
        for(int i=0;i<n;i++){
            m1[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m1.find(t[i])!=m1.end()){
                if(m1[t[i]]>0){
                    m1[t[i]]--;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
