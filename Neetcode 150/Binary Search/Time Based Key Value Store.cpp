class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }
        
        vector<pair<int, string>> &val = mp[key];
        int n = val.size();
        int low = 0, high = n - 1;
        string ans = "";
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (val[mid].first == timestamp) {
                return val[mid].second;
            } else if (val[mid].first < timestamp) {
                ans = val[mid].second;  
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans; 
    }
};
