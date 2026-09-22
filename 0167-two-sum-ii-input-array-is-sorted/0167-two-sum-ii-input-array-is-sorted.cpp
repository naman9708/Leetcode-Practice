class Solution {
public:
int bs(int t,int s,int e,vector<int>& nums){
    while(s<=e){
        int mid = s+((e-s)/2);
        if(nums[mid]==t){
            return mid;
        }
        else if(nums[mid]<t){
            s = mid+1;
        }
        else {
            e = mid-1;
        }
    }
    return -1;
}

    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0;i<nums.size();i++){
            int n = target - nums[i];
            int ans = bs(n,i+1,nums.size()-1,nums);
            if(ans!=-1){
                return {i+1,ans+1};
            }
        }
        return {};
    }
};