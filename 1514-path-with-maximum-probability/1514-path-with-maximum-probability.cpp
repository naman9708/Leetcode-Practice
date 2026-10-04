class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }

        vector<double> dist(n,0.0);

        priority_queue<pair<double,int>> pq;

        vector<bool> vis(n,false);
        pq.push({1.0, start});

        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == end)
                return prob;

            if(vis[node]) continue;
            vis[node] = true;
            for(auto it : adj[node]){
                int a = it.first;
                double probi = it.second;

                double proba = prob * probi;
                 pq.push({proba, a});
                
            }
        }

        return 0.0;
    }
};