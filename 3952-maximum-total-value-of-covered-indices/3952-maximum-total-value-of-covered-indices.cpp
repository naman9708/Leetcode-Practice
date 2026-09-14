class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans  = 0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                i++;
                continue;
            }
            int l = i;
            while(i<n && s[i]=='1'){
                i++;
            }
            int r = i-1;
            int start = max(0,l-1);
            int mn = INT_MAX;
            long long sum = 0;
            for(int i = start;i<=r;i++){
                sum += nums[i];
                mn = min(mn,nums[i]);
            }
            if(l == 0)
            ans += sum;
            else ans+= sum-mn;

        }
        return ans;
    }
};