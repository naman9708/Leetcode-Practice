class Solution {
public:

int solve (int n,int m,vector<int>& nums,vector<int>& dp){
    if(n<m){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
     int p = nums[n] + solve(n-2,m,nums,dp);
     int np = 0+solve(n-1,m,nums,dp);

     return dp[n] = max(p,np);
}
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        if(n==1){
            return nums[0];
        }

        int c1 = solve(n-1,1,nums,dp1);
        int c2 = solve(n-2,0,nums,dp2);

        return max(c1,c2);

    }
};