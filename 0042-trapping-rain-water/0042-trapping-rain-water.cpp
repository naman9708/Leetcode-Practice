class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int lm = 0;
        int rm = 0;
        int l = 0;
        int r = n-1;
        while(l<r){
            lm = max(lm,height[l]);
            rm = max(rm,height[r]);
            if(lm<rm){
                total += lm-height[l];
                l++;
            }
            else {
                total += rm-height[r];
                r--;
            }
        }
        return total;
    }
};