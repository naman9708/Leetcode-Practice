class Solution {
public:
    int dis(vector<vector<int>>& points,int n,int m){
        return abs(points[n][0]-points[m][0]) + abs(points[n][1]-points[m][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, std::vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
        vector<bool> vis(n,false);
        int ans = 0;

        pq.push({0,0});
        while(!pq.empty()){
            auto c = pq.top();
            int w = c.first;
            int node = c.second;
            pq.pop();
            if(vis[node])continue;
            vis[node] = true;
            ans += w;
            for(int i = 0;i<n;i++){
                if(!vis[i]){
                int dis1 = dis(points,i,node);
                pq.push({dis1,i});
                }
            }
        }
            return ans;
    }
};