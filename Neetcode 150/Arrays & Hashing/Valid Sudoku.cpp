class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans=true;
        map<int,int>mp;
        for(int i=0;i<9;i++){
            int co=0;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    co++;
                mp[board[i][j]]++;
                if(mp[board[i][j]]>1){
                    ans=false;
                    cout<<"hi1"<<'\n';
                    return ans;
                }
                }
            }
            mp.clear();
        }
        for(int i=0;i<9;i++){
            int co=0;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    co++;
                mp[board[j][i]]++;
                if(mp[board[j][i]]>1){
                    cout<<"hi2"<<'\n';
                    ans=false;
                    return ans;
                }
                }
            }
            mp.clear();
        }
        vector<pair<int,int>>start;
        for(int i=0;i<=6;i+=3){
            for(int j=0;j<=6;j+=3){
                start.push_back({i,j});
            }
        }
        for(int i=0;i<start.size();i++){
            int start_x=start[i].first;
            int start_y=start[i].second;
            for(int j=start_x;j<=start_x+2;j++){
                int co=0;
                for(int k=start_y;k<=start_y+2;k++){
                    if(board[j][k]!='.'){
                        co++;
                        mp[board[j][k]]++;
                        if(mp[board[j][k]]>1){
                            cout<<"hi3"<<'\n';
                            ans=false;
                            return ans;
                        }
                    }
                }
                //mp.clear();
            }
            mp.clear();
        }
        return ans;
    }
};
