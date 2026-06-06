class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> l(nums.size());
        vector<int> r(nums.size());
        vector<int> ans(nums.size());
        int ls = 0;
        int rs = 0;
        for(int i = 0;i<nums.size();i++){
            l[i] = ls;
            ls+=nums[i];
            r[nums.size()-1-i] = rs;
            rs+=nums[nums.size()-i-1];
        }
        for(int i = 0;i<nums.size();i++){
            ans[i]=(l[i]-r[i]);
            if(ans[i]<0) ans[i]*=-1;
        }
        return ans;
    }
};