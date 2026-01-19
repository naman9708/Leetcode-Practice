class Solution {
public:
    string convert(string s, int rows) {
        if(s.size()==1||rows == 1)return s;
        string ans = "";
        int c = (rows+(rows-2));
        int d = 0;
        for(int i = 1;i<=rows;i++){
            int j = i-1;int cnt = 1;
            while(j<s.size()){
                ans.push_back(s[j]);
                if((i==1||(cnt%2)==1)){
                    if(i==rows){ans.pop_back();}
                    j+=c;
                }
                else if(i==rows||((cnt%2)==0)){
                    j+=d;
                }
                cnt++;
            }
            c-=2;
            d+=2;
        }
        return ans;
    }
};