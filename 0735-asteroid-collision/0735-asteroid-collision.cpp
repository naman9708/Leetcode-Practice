class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        stack<int> st;
        for(int i = 0;i < n;i++){
            bool k = true;
            if(nums[i]>0){
                st.push(nums[i]);
            }
            else {
                while(!st.empty() && -1*(nums[i])>=st.top()){
                    if(st.top()==(-1*nums[i])){
                        st.pop();
                        k = false;
                        break;
                    }
                    else
                    st.pop();
                }
                if(k&&st.empty())arr.push_back(nums[i]);
            }
        }
        stack<int> arr1;
        while(!st.empty()){
            arr1.push(st.top());
            st.pop();

        }
        while(!arr1.empty()){
            arr.push_back(arr1.top());
            arr1.pop();
        }
        return arr;
    }
};