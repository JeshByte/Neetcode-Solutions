class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        while (j < n) {
            mp[s[j]]++;
            if (mp[s[j]] == 1) {
                j++;
            } else {
                ans = max(ans, j - i);
                while (mp[s[j]] > 1) {
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        ans = max(ans, j - i);
        return ans;
    }
};
