class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> un;
        vector<int> ans;

        for(int i = 0;i<nums.size();i++){
            un[nums[i]]++;
        }
        for(int i = 1;i<=nums.size();i++){
            if(!un.contains(i)) ans.push_back(i);
        }
        return ans;
    }
};