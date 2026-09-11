class Solution {
public:
bool k = true;
void dfs(vector<vector<int>>& nums,vector<vector<int>>& nums1,int i,int j){
    if(i>=nums.size()||i<0||j>=nums[0].size()||j<0||nums[i][j]==0){
            return;
        }

        nums[i][j] = 0;
    if(nums1[i][j]==0){
            k = false;
        }


        dfs(nums,nums1,i+1,j);
        dfs(nums,nums1,i,j+1);
        dfs(nums,nums1,i-1,j);
        dfs(nums,nums1,i,j-1);
    
        
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n= grid1.size();
        int m = grid1[0].size();
        int cnt  = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                    if(grid2[i][j]==1){
                        k = true;
                        dfs(grid2,grid1,i,j);
                        if (k) cnt++;
                    }
                
            }
        }
        return cnt;
    }
};