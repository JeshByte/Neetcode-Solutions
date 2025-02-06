class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp1,mp2;
        int n1=s1.size();
        int n2=s2.size();
        for(int i=0;i<n1;i++){
            mp1[s1[i]]++;
        }
        int i=0,j=0;
        while(j<n2){
            mp2[s2[j]]++;
            if((j-i+1)<n1){
                j++;
                continue;
            }
            if(mp1==mp2){
                return true;
            }
            mp2[s2[i]]--;
            if(mp2[s2[i]]<=0){
                mp2.erase(s2[i]);
            }
            i++;
            j++;
        }
        return false;
    }
};
