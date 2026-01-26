class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> arr1;
        int temp = INT_MAX;
            for(int i = 1;i<arr.size();i++){
                int sub = arr[i]-arr[i-1];
                if(temp>sub){
                    arr1.clear();
                    arr1.push_back({arr[i-1],arr[i]});
                    temp = sub;
                }
                else if(temp == sub)arr1.push_back({arr[i-1],arr[i]});

            }
            return arr1;
        
    }
};