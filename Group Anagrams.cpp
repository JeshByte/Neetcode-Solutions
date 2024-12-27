class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(int i=0;i<n;i++){
            string word=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(word);
        }   
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};
