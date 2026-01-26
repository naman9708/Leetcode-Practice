class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n  = nums.size();
        int area = INT_MIN;
        stack<int> st;
        for(int i = 0;i<=n;i++){
            while(!st.empty()&&(i==n || nums[st.top()]>nums[i])){
                int l = nums[st.top()];
                st.pop();
                int b = st.empty()?i:i-st.top()-1;
                area = max(area,l*b);
            }

            st.push(i);
        }
        return area;
    }
};