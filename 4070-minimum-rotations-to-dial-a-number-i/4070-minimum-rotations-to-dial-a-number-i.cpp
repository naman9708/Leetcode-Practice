class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        s = '0'+s;
        for(int i = 1;i<s.size();i++){
            int mini = min(s[i-1]-'0',s[i]-'0');
            
            int maxi = max(s[i-1]-'0',s[i]-'0');
            
            if((10+mini)-maxi<abs(maxi-mini)){
                ans+=((10+mini)-maxi);
                cout<<10+mini-maxi<<" ";
            }
            else {
                ans+=abs(maxi-mini);
                cout<<maxi-mini<<" ";
            }

        }
        return ans;
    }
};