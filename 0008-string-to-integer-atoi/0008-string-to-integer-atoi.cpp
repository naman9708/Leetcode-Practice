class Solution {
public:
    int myAtoi(string s) {
        if((s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z')||s[0]=='.')return 0;
        bool digit = false;
        bool c = false;
        double ans = 0;
        for(int i = 0;i<s.size();i++){
            if(!digit && s[i]==' ')continue;
            else if(digit== true && (s[i]<'0'|| s[i]>'9'))break;
            else if(s[i]=='+'||s[i]=='-'||(s[i]>='0'&&s[i]<='9')) {
                if(s[i] == '-') c = true;
                else if(s[i]== '+') {
                    digit = true;
                    continue;
                }
                else {
                    ans =  (ans * 10) + int(s[i] - '0');
                }
                digit = true;
            }
            else {
                return 0;
            }
        }
        if(c){
            ans = -ans;
            if(ans < INT_MIN){
                ans = INT_MIN;
            }
        }
        if(ans > INT_MAX){
            ans =  INT_MAX;
        }

        return (int)ans;
    }
};