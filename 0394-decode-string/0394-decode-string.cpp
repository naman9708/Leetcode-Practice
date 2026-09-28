class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(int i = 0;i < s.size();i++){
            if(s[i] == ']'){
                string k = "";

                while(st.top() != '['){
                    k.push_back(st.top());
                    st.pop();
                }

                st.pop();
                reverse(k.begin(), k.end());

                string num = "";

                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    num.push_back(st.top());
                    st.pop();
                }

                reverse(num.begin(), num.end());

                int n = stoi(num);

                string t = "";

                for(int j = 0;j < n;j++){
                    t += k;
                }

                for(int j = 0;j < t.size();j++){
                    st.push(t[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }

        s = "";

        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }

        reverse(s.begin(), s.end());

        return s;
    }
};