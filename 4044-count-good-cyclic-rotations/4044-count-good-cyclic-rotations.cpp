class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long t  = 0;
        long long k = 0;
        int m = nums.size()/2;
        for(int i = 0;i<nums.size();i++){
            t += nums[i];
            if(i<m){
                k+=nums[i];
            }
        }
        int ans  = 0;
        if(k>t-k){
            ans++;
        }

        for(int i = 0;i<nums.size()-1;i++){
            k-=nums[(m-i-1+nums.size())%nums.size()];
            k+=nums[(nums.size()-i-1+nums.size())%nums.size()];
            if(k>t-k)ans++;
        }
        return ans;
    }
};