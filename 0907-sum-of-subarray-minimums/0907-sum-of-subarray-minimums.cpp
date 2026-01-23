class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int total = 0;
        vector<int> ns(arr.size());
        stack<int> st;
        for(int i = arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i])st.pop();
            if(st.empty())ns[i]=arr.size();
            else ns[i] = st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        vector<int> ps(arr.size());
        for(int i = 0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>arr[i])st.pop();
            if(st.empty())ps[i]=-1;
            else ps[i] = st.top();
            st.push(i);
        }

        long mod = 1e9 + 7;
        for(int i = 0;i< arr.size();i++){
            int l = i-ps[i];
            int r = ns[i]-i;
            long long fre = (l*r*1LL)%mod;
            int val = (arr[i]*fre*1LL)%mod;
            total = (total+val)%mod;
        }
        return total;
    }
};