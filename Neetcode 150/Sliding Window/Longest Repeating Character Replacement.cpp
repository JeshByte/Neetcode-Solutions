class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        map<char,int>mp;
        int ma=-1;
        char ma_ch;
        int ans=-1;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]>ma){
                ma=mp[s[j]];
                ma_ch=s[j];
            }
            if((j-i+1)-ma<=k){
                j++;
                continue;
            }
            else{
                ans=max(ans,j-i);
                while((j-i+1)-ma>k){
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};
