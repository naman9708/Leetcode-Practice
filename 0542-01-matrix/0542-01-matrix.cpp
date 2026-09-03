class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;

        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            auto k = q.front();
            q.pop();
            int n = k.first;
            int m = k.second;

            if(n-1>=0 && mat[n-1][m]==-1){
                mat[n-1][m] = mat[n][m] +1;
                q.push({n-1,m});
            }
            if(n+1<mat.size() && mat[n+1][m]==-1){
                mat[n+1][m] = mat[n][m] +1;
                q.push({n+1,m});
            }
            if(m-1>=0 && mat[n][m-1]==-1){
                mat[n][m-1] = mat[n][m] + 1;
                q.push({n,m-1});
            }
            if(m+1<mat[0].size() && mat[n][m+1]==-1){
                mat[n][m+1] = mat[n][m] +1;
                q.push({n,m+1});
            }

        }
        return mat;
    }
};