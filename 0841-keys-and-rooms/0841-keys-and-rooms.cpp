class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool>& vis,int i){
        vis[i] = true;
        for(int n : rooms[i]){
        if(!vis[n]){
            dfs(rooms,vis,n);
        }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        vis[0] = true;
        dfs(rooms,vis,0);
        for(int i = 0;i<rooms.size();i++){
            if(!vis[i])return false;
        }
        return true;
    }
};