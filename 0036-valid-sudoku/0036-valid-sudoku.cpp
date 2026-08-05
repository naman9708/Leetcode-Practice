class Solution {
public:
bool solve(vector<vector<char>>& board){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(board[i][j]>='1'&&board[i][j]<='9'){
                if(!valid(board,i,j,board[i][j])){
                    return false;

                }
                
            }
        }
    }
    return true;
}

bool valid(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (i != col &&board[row][i] == num) return false;
        if (i != row &&board[i][col] == num) return false;

        int r = 3 * (row / 3) + i / 3;
        int c = 3 * (col / 3) + i % 3;
        if ((r != row || c != col) && board[r][c] == num) return false;
    }
    return true;
}


    bool isValidSudoku(vector<vector<char>>& board) {
       return solve(board);
    }
};