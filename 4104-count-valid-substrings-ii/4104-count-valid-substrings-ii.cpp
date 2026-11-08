class Solution {
public:
    long long countValidSubstrings(string s) {
        int a = -1;
        int b = -1;
        int c  = -1;
        int cnti = 0;
        long long cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='a'){
                a = i;
            }
            else if(s[i]=='b'&&a!=-1)b = a;
            else if(s[i]=='c'&&b!=-1){
                if(b+1 > cnti){
                cnt += (b+1-cnti)*(s.size()-i);
                cnti = b+1;
                }
            }
        }
        long long n = s.size();
        long long t = (n*(n+1))/2;
        return t-cnt;
    }
};