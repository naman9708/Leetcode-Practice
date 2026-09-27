class Solution {
public:
int f(int n,vector<int>& nums,vector<int>& dp){
    if(n == 0)return nums[n];
    if(n<0) return 0;
    if(dp[n]!=-1){
        return dp[n];
    }

    int a  =nums[n] + f(n-2,nums,dp);
    int b  = 0+ f(n-1,nums,dp);

     return dp[n] = max(a,b);

}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp);
    }
};