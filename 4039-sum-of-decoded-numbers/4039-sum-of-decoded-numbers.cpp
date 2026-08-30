class Solution {
public:
const long long MOD = 1e9 + 7;
long long power(long long x, long long y){
    long long ans = 1;

    while(y > 0){
        if(y & 1){
        ans = ans * x % MOD;
        }

        x = x * x % MOD;
        y /= 2;
    }

    return ans;
}
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(int j = 0;j<nums.size();j++){
        long long n  = nums[j];
        int w  = n%10;
        long long d = n/10;
        long long temp = d;
        int digits = 0;
        while (temp > 0){
            digits++;
            temp /= 10;
        }
        long long p = 1;
        for(int i = 0;i<digits-w;i++){
            p*=10;
        }
        long long x = d/p;
        long long y = d%p;
        cout<<x<<"  "<<y;
        
        
            ans = (ans+power(x,y))%MOD;

        }

        return ans;
    }
};