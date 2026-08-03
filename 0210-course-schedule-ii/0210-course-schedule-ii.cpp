class Solution {
public:
bool isc(int src,vector<bool>& vis,vector<bool>& rep,vector<vector<int>>& p){
    vis[src] = true;
    rep[src] = true;
    for(int i = 0;i<p.size();i++){
        int u = p[i][1];
        int v = p[i][0];
        if(u == src){
            if(!vis[v]){
                if(isc(v,vis,rep,p)){
                    return true;
                }
            }
            else if(rep[v]){
                return true;
            }
        }
    }
    rep[src] = false;
    return false;
}
void tp(int src,vector<bool>& vis,stack<int>& st,vector<vector<int>>& p){
    vis[src] = true;
    for(int i = 0;i<p.size();i++){
        int u = p[i][1];
        int v = p[i][0];
        if(src == u){
            if(!vis[v]){
                tp(v,vis,st,p);
            }
        }
    }
    st.push(src);
}

    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<bool> vis(n,false);
        vector<bool> rep(n,false);
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(isc(i,vis,rep,p)){
                    return ans;
                }
            }
        }
        fill(vis.begin(), vis.end(), false);
        stack<int> st;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                tp(i,vis,st,p);
            }
        }
        while(!st.empty()){
            int a = st.top();
            ans.push_back(a);
            st.pop();
        }
        return ans;

    }
};