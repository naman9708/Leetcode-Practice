class Solution {
public:

    int missingMultiple(vector<int>& nums, int k) {
        vector<int> temp(101,0);
        for(int i = 0;i<nums.size();i++){
            temp[nums[i]]=1;
        }
    int i = k;
        while(i<=100){
            if(temp[i]==1){
                i+=k;
                continue;
            }
            else return i;
        }
        return i;
        
    }
};