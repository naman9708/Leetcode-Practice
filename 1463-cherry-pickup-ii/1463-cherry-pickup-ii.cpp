class Solution {
public:

    int f(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1){
            if(j1==j2)return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int d = -1e8;
        for(int h = -1;h<2;h++){
            for(int j = -1;j<2;j++){
                int v = grid[i][j1];
                if(j1==j2){
                    v += f(i+1,j1+h,j2+j,grid,dp);
                }
                else v+=grid[i][j2]+f(i+1,j1+h,j2+j,grid,dp);

                d = max(d,v);
            }
        }

        return dp[i][j1][j2] = d;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int i = grid.size();
        int j = grid[0].size();
        vector<vector<vector<int>>> dp(i, vector<vector<int>>(j,vector<int>(j,-1)));
        return f(0,0,j-1,grid,dp);


    }
};