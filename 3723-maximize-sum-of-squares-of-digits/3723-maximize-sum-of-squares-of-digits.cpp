class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num<sum) return "";
        string ans  = "";
        while(num>0){
            int n = min(9,sum);
            ans += to_string(n);
            sum-=n;
            num--;
        }
        return ans;
    }
};