class Solution {
public:
    int strStr(string hay, string needle) {
        int n = 0;
        for(int i = 0;i<hay.size();i++){
            if(hay[i]==needle[n]){
                n++;
            }
            else {
                i = i-n;
                n = 0;
            }
            if(n==needle.size()){
                return i-n+1;
            }
        }
        return -1;
    }
};