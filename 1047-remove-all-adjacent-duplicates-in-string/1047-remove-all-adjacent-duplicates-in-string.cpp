class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push('-1');
        for(char c : s){
            if(st.top()==c){
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        if(st.top()=='-1')return "";
        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        s.pop_back();
        reverse(s.begin(),s.end());
        return s;
    }
};