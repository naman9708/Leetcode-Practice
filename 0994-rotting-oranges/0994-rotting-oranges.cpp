class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j] == 2){
                vis[i][j] = 1;
                q.push({{i,j},0});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){

            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front ().second;
            q.pop();
            ans = max(ans,t);
            if(i<n-1 && vis[i+1][j]==0 && arr[i+1][j]==1){
                q.push({{i+1,j},t+1});
                vis[i+1][j] = 1;
            }
            if(i>0 && vis[i-1][j]==0 && arr[i-1][j]==1){
                q.push({{i-1,j},t+1});
                vis[i-1][j] = 1;                
            }
            if(j<m-1 && vis[i][j+1]==0 && arr[i][j+1]==1){
                q.push({{i,j+1},t+1});
                vis[i][j+1] = 1;                
            }
            if(j>0 && vis[i][j-1]==0 && arr[i][j-1]==1){
                q.push({{i,j-1},t+1});
                vis[i][j-1] = 1;                
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(vis[i][j] == 0 &&arr[i][j]==1)return -1;
            }
        }
        return ans;
    }
};