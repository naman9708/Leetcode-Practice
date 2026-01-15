class Solution {
public:

    void fs(int ind,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans,int k,int n){
        if(ds.size()==k){
            if(n == 0){
                ans.push_back(ds);
            }
            return;
        }

        for(int i = ind;i<9;i++){
            if(arr[i]>n)break;
            ds.push_back(arr[i]);
            fs(i+1,arr,ds,ans,k,n-arr[i]);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr(9);
        for(int i = 0;i<9;i++){
            arr[i]= i+1;
        }
        vector<vector<int>> ans;
        vector<int> ds;
        fs(0,arr,ds,ans,k,n);
        return ans;

    }
};