class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1(n);
        stack<int> st1;
        for(int i = n-1;i>=0;i--){
            while(!st1.empty()&&nums[st1.top()]>=nums[i])st1.pop();
            if(st1.empty())arr1[i] = n;
            else arr1[i] = st1.top();
            st1.push(i);
        }

        vector<int> arr2(n);
        stack<int> st2;
        for(int i = 0;i<n;i++){
            while(!st2.empty()&&nums[st2.top()]>nums[i])st2.pop();
            if(st2.empty())arr2[i] = -1;
            else arr2[i] = st2.top();
            st2.push(i);
        }
        vector<int> arr3(n);
        stack<int> st3;
        for(int i = n-1;i>=0;i--){
            while(!st3.empty()&&nums[st3.top()]<=nums[i])st3.pop();
            if(st3.empty())arr3[i] = n;
            else arr3[i] = st3.top();
            st3.push(i);
        }
        vector<int> arr4(n);
        stack<int> st4;
        for(int i = 0;i<n;i++){
            while(!st4.empty()&&nums[st4.top()]<nums[i])st4.pop();
            if(st4.empty())arr4[i] = -1;
            else arr4[i] = st4.top();
            st4.push(i);
        }
        long long total1 = 0;
        for(int i = 0;i<n;i++){
            int l = i-arr2[i];
            int r = arr1[i]-i;
            total1 += (1LL*l*r*nums[i]);
        } 
        long long total2 = 0;
        for(int i = 0;i<n;i++){
            int l = i-arr4[i];
            int r = arr3[i]-i;
            total2 += (1LL*l*r*nums[i]);
        }

        return total2 - total1;

    }
};