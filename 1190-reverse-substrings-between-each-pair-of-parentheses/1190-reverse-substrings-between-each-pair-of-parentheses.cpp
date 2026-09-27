class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            if(s[i]==')'){
                string sc = "";
                while(st.top()!='('){
                    char c = st.top();
                    st.pop();
                    sc.push_back(c);
                }
                    st.pop();
                    for(int j = 0;j<sc.size();j++){
                        st.push(sc[j]);
                    }
                
            }
            else
            st.push(s[i]);
        }
        s = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            s.push_back(c);
        }
        reverse(s.begin(),s.end());
        return s;
    }
};