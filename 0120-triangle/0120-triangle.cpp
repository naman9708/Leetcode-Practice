class Solution {
public:
    int f(int i,int j,vector<vector<int>>& tr,vector<vector<int>>& dp,vector<vector<int>>& vis){
        if(i == tr.size()-1)return tr[i][j];
        if(vis[i][j] != 0) return dp[i][j];
        vis[i][j] = 1;
        int d = f(i+1,j,tr,dp,vis);
        int dr = f(i+1,j+1,tr,dp,vis);
        dp[i][j] = tr[i][j] + min(d,dr);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& tr) {
        int n  = tr.size();
        int m = tr[0].size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<int>> vis(n,vector<int>(n,0));
        return f(0,0,tr,dp,vis);
        
    }
};