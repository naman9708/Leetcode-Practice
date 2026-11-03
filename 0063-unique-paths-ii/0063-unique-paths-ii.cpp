class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i>=0 &&j>=0 && grid[i][j]==1)return 0;
        if(i==0 && j==0)return 1;
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int u = f(i-1,j,grid,dp);
        int l = f(i,j-1,grid,dp);
        return dp[i][j] = u+l; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int i = grid.size();
        int j = grid[0].size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return f(i-1,j-1,grid,dp);

    }
};