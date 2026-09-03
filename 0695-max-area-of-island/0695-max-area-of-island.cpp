class Solution {
public:
    int dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid,int n){
        if(i<0 || i>=grid.size() ||
                j<0 || j>=grid[0].size()) {
                return n;
                }

                if(vis[i][j]||grid[i][j]==0)return n;

        vis[i][j]= true;
        n++;

        n = dfs(i+1,j,vis,grid,n);
        n = dfs(i-1,j,vis,grid,n);
        n = dfs(i,j+1,vis,grid,n);
        n = dfs(i,j-1,vis,grid,n);

        return n;
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
            
                
                if(!vis[i][j]&&grid[i][j]==1){

                   ans = max(ans,dfs(i,j,vis,grid,0));
                }
                 
            }
        }
        return ans;
    }
};