class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int l = 0;
        int r = tokens.size() - 1;
        int s = 0;
        int ans = 0;

        while(l <= r){
            if(power >= tokens[l]){
                power -=tokens[l];
                s++;
                l++;
                ans = max(ans,s);
            }
            else if(s > 0){
                power +=tokens[r];
                s--;
                r--;
            }
            else{
                break;
            }
        }

        return ans;
    }
};