class Solution {
public:

    vector<int> gf(int x){
        vector<int> f;

        for (int i = 2;i * i<= x;i++){
            if (x % i== 0) {
                f.push_back(i);

                while (x %i == 0)
                    x /= i;
            }
        }

        if (x > 1)
            f.push_back(x);

        return f;
    }

int longestSubarray(vector<int>& nums, int k) {
    int n = nums.size();

    vector<vector<int>> f(n);
    for (int i = 0;i < n;i++)
        f[i] = gf(nums[i]);

    unordered_map<int, int> freq;

    int l = 0, ans = 0;

    for(int r = 0;r < n;r++){

        for(int p : f[r])
            freq[p]++;

        while(freq.size()>k){

            for(int p : f[l]){
                freq[p]--;

                if(freq[p] == 0)
                    freq.erase(p);
            }

            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}
};