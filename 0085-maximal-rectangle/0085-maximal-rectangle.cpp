class Solution {
public:

    int his(vector<int>& arr,int n){
        stack<int> st;
        int area = INT_MIN;
        for(int i = 0;i<=n;i++){
            while(!st.empty()&&(i == n || arr[st.top()]>arr[i])){
                int l = arr[st.top()];
                st.pop();
                int w = st.empty()?i:i-st.top()-1;
                area = max(area , l*w);
            }
            st.push(i);
        }
        return area;
    }


    int maximalRectangle(vector<vector<char>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        if(m == 1 &&n==1)return nums[0][0]-'0';
        vector<vector<int>> pre(n,vector<int>(m));
        for(int i = 0;i<m;i++){
            int sum = 0;
            for(int j = 0; j<n; j++){
                if(nums[j][i]-'0'==0)sum = 0;
                sum += nums[j][i]-'0';
                pre[j][i] = sum;
            }
        }
        int area = INT_MIN;
        for(int i = 0;i<n;i++){
            area = max(area,his(pre[i],m));
        }
        return area;

    }
};