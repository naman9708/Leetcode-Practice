class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        vector<pair<int,vector<int>>> temp;
        // ans.push_back(points[0]);
        int mini = INT_MIN;
        for(int i = 0;i<points.size();i++){
            int c = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            temp.push_back({c,points[i]});
        }
        sort(temp.begin(),temp.end());

        for(int i = 0;i<temp.size();i++){
            ans.push_back(temp[i].second);
            k--;
            if(k==0)break;
        }
        return ans;
    }
};