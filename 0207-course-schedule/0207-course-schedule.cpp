class Solution {
public:
    bool dfs(int n,vector<vector<int>>& pre,vector<bool>& vis,vector<bool>& r){
        vis[n] = true;
        r[n] = true;
        for(int i= 0;i<pre.size();i++){
            int u = pre[i][0];
            int v = pre[i][1];
            if(u == n){
            if(!vis[v]){
                if(dfs(v,pre,vis,r)){
                    return true;
                }
            }
            else if(r[v]){
                return true;
            }
            }
        }
        r[n] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        if(pre.size()==0)return true;
        vector<bool> vis(numCourses,false);
        vector<bool> r(numCourses,false);
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
            if(dfs(i,pre,vis,r)){
                return false;
            }}
        }
        return true;
    }
};