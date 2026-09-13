class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> arr;
        vector<pair<int,int>> arrr;
        for(int i = 0;i<img1.size();i++){
            for(int j = 0;j<img1[0].size();j++){
                if(img1[i][j]==1){
                    arr.push_back({i,j});
                }
                if(img2[i][j]==1){
                    arrr.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int> mp;
        for(int i = 0;i<arr.size();i++){
            for(int j = 0;j<arrr.size();j++){
                auto k = arr[i];
                auto l = arrr[j];
                int x1 = k.first;
                int x2 = k.second;
                int y1 = l.first;
                int y2 = l.second;
                mp[{x1-y1,x2-y2}]++;
            }
        }
        int maxi = 0;
        for (const auto& [key_pair, value] : mp) {
            int x = key_pair.first;
            int y = key_pair.second;
            maxi = max(maxi,value);

        }
        return maxi;
    }
};