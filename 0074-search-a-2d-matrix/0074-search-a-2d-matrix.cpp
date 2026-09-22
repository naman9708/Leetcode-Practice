class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int s  = 0;
        int e = m*n-1;
        while(s<=e){
            int mid = s+((e-s)/2);
            int v = matrix[mid/m][mid%m];
            if(v == target){
                return true;
            }
            else if(v<target) s= mid+1;

            else e = mid-1;
        }
        return false;
    }
};