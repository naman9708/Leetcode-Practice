class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        int a = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                st.push(0);
            }
            else {
                int b = st.top();
                st.pop();
                if(b == 0){
                    st.top()+=1;
                }
                else{
                    st.top() += 2*b;
                }
            }
        }
        
        return st.top();
    }
};