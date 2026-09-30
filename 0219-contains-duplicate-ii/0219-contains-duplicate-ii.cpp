class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,vector<int>> seen;
        for(int i = 0;i<nums.size();i++){
            seen[nums[i]].push_back(i);
        }
        bool c = false;
        for(auto&[key,val]:seen){
            if(seen[key].size()>1){
                c = true;
         for(int j = 1;j<val.size();j++){
                if(val[j]-val[j-1]<=k)return true;
            }}}
            if(!c)return false;
        return false;
    }
};