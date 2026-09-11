class Solution {
public:
bool dfs(vector<vector<int>>& nums,int i,int j){
    if(i>=nums.size()||i<0||j>=nums[0].size()||j<0){
            return false;
        }
    if(nums[i][j]==1||nums[i][j]==2){
            return true;
        }
        nums[i][j] = 2;

        bool a = dfs(nums,i+1,j);
        bool b = dfs(nums,i,j+1);
        bool c = dfs(nums,i-1,j);
        bool d = dfs(nums,i,j-1);

        return a && b && c && d;
        
}
void dfs1(vector<vector<int>>& nums,int i,int j){
    if(i>=nums.size()||i<0||j>=nums[0].size()||j<0||nums[i][j]!=0){
            return;
        }
        nums[i][j] = 2;

        dfs(nums,i+1,j);
        dfs(nums,i,j+1);
        dfs(nums,i-1,j);
        dfs(nums,i,j-1);
}
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==0)
                        dfs1(grid,i,j);
                }
            }
        }
        int cnt  = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                    if(grid[i][j]==0){
                        if(dfs(grid,i,j))cnt++;
                    }
                
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                  cout<<grid[i][j]<<" ";
                
            }
            cout<<endl;
        }
        return cnt;
    }
};