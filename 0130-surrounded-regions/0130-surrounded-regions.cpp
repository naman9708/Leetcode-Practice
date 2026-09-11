class Solution {
public:
    void dfs(vector<vector<char>>& nums,int i,int j){
        if(i>=nums.size()||i<0||j>=nums[0].size()||j<0||nums[i][j]!='O'){
            return;
        }
        nums[i][j] = '*';

        dfs(nums,i+1,j);
        dfs(nums,i,j+1);
        dfs(nums,i-1,j);
        dfs(nums,i,j-1);

    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(i==0||i == board.size()-1||j==0 || j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        dfs(board,i,j);
                    }
                }
            }
        }

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='*'){
                    board[i][j]='O';
                }
            }
        }
    }
};