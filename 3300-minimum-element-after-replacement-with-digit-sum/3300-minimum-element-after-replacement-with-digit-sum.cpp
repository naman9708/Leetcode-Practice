class Solution {
public:
    int minElement(vector<int>& nums) {
        int sum = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            int n = nums[i];
            int add = 0;
            while(n!=0){
                int k = n%10;
                n/=10;
                add+=k;
            }
            sum = min(sum,add);
        }
        return sum;
    }
};