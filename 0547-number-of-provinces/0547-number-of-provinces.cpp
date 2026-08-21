class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,vector<int>& vis){
        vis[i] = true;
        for(int j = 0;j<adj[i].size();j++){
            if(adj[i][j]==1 && !vis[j]){
                dfs(j,adj,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        vector<int> vis(adj[0].size(),0);
        int n  = adj[0].size();
        int pr = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                pr++;
                dfs(i,adj,vis);
            }
        }
        return pr;
    }
};