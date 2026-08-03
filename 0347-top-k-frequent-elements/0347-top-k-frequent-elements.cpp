class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==1)return {nums[0]};
        vector<pair<int,int>> freq;
        sort(nums.begin(),nums.end());
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                freq.push_back({nums[i-1], cnt});
                cnt = 1;
            } 
            else {
                cnt++;
            }
        }

        freq.push_back({nums.back(), cnt});
            
        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        int p = k;
        vector<int> ans;
        for(int i= freq.size()-1;i>=0;i--){
            ans.push_back(freq[i].first);
            p--;
            if(p==0)break;
        }
        return ans;
    }
};