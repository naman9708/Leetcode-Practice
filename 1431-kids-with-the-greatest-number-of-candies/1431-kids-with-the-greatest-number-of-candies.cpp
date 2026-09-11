class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        vector<bool> ans(candies.size());
        int maxi = candies[0];
        for(int i = 1;i<candies.size();i++){
            maxi = max(candies[i],maxi);
        }
        for(int i = 0;i<candies.size();i++){
            if(candies[i]+extra>=maxi)
                ans[i] = true;
            
            else ans[i] = false;
        }
        return ans;
    }
};