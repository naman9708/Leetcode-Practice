class Solution {
public:
void dfs(vector<vector<int>>& nums,int i,int j){
    if(i>=nums.size()||i<0||j>=nums[0].size()||j<0||nums[i][j]!=1){
            return;
        }
        nums[i][j] = 2;

        dfs(nums,i+1,j);
        dfs(nums,i,j+1);
        dfs(nums,i-1,j);
        dfs(nums,i,j-1);
}

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==1)
                        dfs(grid,i,j);
                }
            }
        }
        int cnt  = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
        }

        return cnt;

    }
};