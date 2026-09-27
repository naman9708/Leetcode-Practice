class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int> mp;
        int ans = 0;
        for(int i = 1;i<nums.size();i++){
            int a = nums[i];
            int b = nums[i-1];
            if(nums[i]==nums[i-1])ans++;
            else{
                if(a>b)
                mp[{b,a}]++;
                else mp[{a,b}]++;
            }
        }
        int k  = 0;
        for(const auto& [key, value] : mp){
            k = max(k,value);
        }
        return ans + k;

    }
};