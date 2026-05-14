class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size()<=1)return false;
        int maxi = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>maxi) maxi = nums[i];
        }
        if(maxi!=nums.size()-1)return false;
        sort(nums.begin(),nums.end());
        
        for(int i = 1;i<nums.size()-1;i++){
            if(nums[i]==nums[i-1]+1){
                continue;
            }
            else return false;
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return false;
        }
        return true;
    }
};