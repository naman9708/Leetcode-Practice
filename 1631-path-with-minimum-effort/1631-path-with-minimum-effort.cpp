class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int c = heights[0].size();
        int r  = heights.size();
        vector<vector<int>> temp(heights.size(),vector<int>(heights[0].size(),0));
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        int ans = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto n = pq.top();
            pq.pop();
            int e = n.first;
            int j = n.second.first;
            int k = n.second.second;
            if(temp[j][k]==1){
                continue;

            }
            temp[j][k] = 1;
            if(j==r-1&&k==c-1)return e;

            if(j-1>=0&& !temp[j-1][k]){
                int ef = abs(heights[j][k] - heights[j - 1][k]);
                pq.push({max(ef, e), {j - 1, k}});                
            }

            if(j+1<=r-1&& !temp[j+1][k]){
                int ef = abs(heights[j][k] - heights[j + 1][k]);
                pq.push({max(ef, e), {j + 1, k}});                
            }

            if(k-1>=0&& !temp[j][k-1]){
                int ef = abs(heights[j][k] - heights[j][k-1]);
                pq.push({max(ef, e), {j, k-1}});                
            }

            if(k+1<=c-1&& !temp[j][k+1]){
                int ef = abs(heights[j][k] - heights[j][k+1]);
                pq.push({max(ef, e), {j, k+1}});                
            }
            ans = max(ans,e);

        }
        return ans;
    }
};