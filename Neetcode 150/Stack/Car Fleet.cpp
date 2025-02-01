class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>comp;
        int n=speed.size();
        for(int i=0;i<n;i++){
            comp.push_back({position[i],speed[i]});
        }
        sort(comp.rbegin(),comp.rend());
        // for(int i=0;i<n;i++){
        //     cout<<comp[i].first<<" "<<comp[i].second<<'\n';
        // }
        int ans=0;
        double curr=0;
        for(int i=0;i<n;i++){
            double temp=(double)(target-comp[i].first)/(comp[i].second);
            if(temp>curr){
                //cout<<temp<<" "<<curr<<'\n';
                ans++;
                curr=temp;
            }
        }
        return ans;
    }
};
