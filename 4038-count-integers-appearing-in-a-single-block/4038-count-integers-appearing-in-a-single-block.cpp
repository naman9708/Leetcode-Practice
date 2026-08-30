class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans =  0;
        for(auto p : mp){
            vector<int> v = p.second;
            bool spec = true;
            for(int i = 1; i < v.size(); i++){ 
                if(v[i] != v[i-1] + 1){
                    spec = false; break;
                }
            } 
            if(spec) ans++;
            }
        return ans;
    }
};