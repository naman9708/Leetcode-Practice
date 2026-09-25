class Solution {
public:

bool dfs(int n,int c,vector<int>& vis,vector<vector<int>>& graph){
    vis[n] = c;
    for(int nei : graph[n]){
        if(vis[nei]==-1){
            if(!dfs(nei,!c,vis,graph)){
                return false;
            }
        }
        if(vis[nei]==vis[n]){
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n  = graph.size();
        vector<int> vis(n,-1);
        for(int i = 0;i < n; i++){
            if(vis[i]==-1){
                if(!dfs(i,0,vis,graph))return false;
            }
        }
        return true;
    }
};