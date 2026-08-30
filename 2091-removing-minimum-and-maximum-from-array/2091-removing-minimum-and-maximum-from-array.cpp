class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();
        int mi = 0;
        int mx = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[mi])
                mi = i;
            if(nums[i] > nums[mx])
                mx = i;
        }

        int left = min(mi, mx);
        int right = max(mi, mx);
        int ans = right + 1;
        ans = min(ans, n - left);
        ans = min(ans, left + 1 + n - right);

        return ans;
    }
};
