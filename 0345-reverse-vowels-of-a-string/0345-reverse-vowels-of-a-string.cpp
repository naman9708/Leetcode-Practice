class Solution {
public:
    string reverseVowels(string s) {
        vector<char> temp;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                temp.push_back(s[i]);
            }
            else continue;
        }
        string ans = "";
        int j = temp.size()-1;
        for(int i =0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                ans+=temp[j];
                j--;
            }
            else {
                ans+=s[i];
            }
        }
        return ans;
    }
};