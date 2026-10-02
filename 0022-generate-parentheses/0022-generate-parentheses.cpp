class Solution {
public:
    vector<string> p(int o,int c ,int n, string & temp, vector<string>& ans){
        if(o == n && c == n){
            ans.push_back(temp);
            return ans;
        }
        // if(temp == ""){
        //     temp.push_back('(');
        //     o++;
        // }
        if(o<n){
        temp+='(';
        p(o+1,c,n,temp,ans);
        temp.pop_back();
        }
        if(c < o){
            temp+=')';
            p(o,c+1,n,temp,ans);
            temp.pop_back();
        }
        
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        return p(0,0,n,temp,ans);
    }
};