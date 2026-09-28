class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string> mp;
        for(int i = 0;i<k.size();i++){
            mp[k[i][0]] = k[i][1];
        }
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            if(s[i]==')'){
                string sk = "";
                while(st.top()!='('){
                    sk.push_back(st.top());
                    st.pop();
                }
                st.pop();
                reverse(sk.begin(),sk.end());
                string t="";
                if(mp.find(sk)!=mp.end()){
                    t = mp[sk];
                }
                else {
                    t = "?";
                }
                for(int j = 0;j<t.size();j++){
                    st.push(t[j]);
                }
            }
            else
            st.push(s[i]);
        }
        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;

    }
};