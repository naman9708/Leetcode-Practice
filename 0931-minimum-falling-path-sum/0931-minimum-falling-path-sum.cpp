class Solution {
public:

int f(int n,int m,vector<vector<int>>& nums,vector<vector<int>>& dp,vector<vector<int>>& vis){
    if(m>=nums[0].size()|| m<0) return 1e8;
    if(n == 0)return nums[0][m];
    if(vis[n][m]) return dp[n][m];
    vis[n][m] = 1;
    int u = nums[n][m]+f(n-1,m,nums,dp,vis);
    int l = nums[n][m]+f(n-1,m-1,nums,dp,vis);
    int r = nums[n][m]+f(n-1,m+1,nums,dp,vis);
    return dp[n][m] = min({u,l,r});
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = INT_MAX;
        for(int j = 0;j < m;j++){
            ans = min(ans, f(n-1,j,matrix,dp,vis));
        }

        return ans;
    }
};