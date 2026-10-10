class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st;
        stack<int>bt;
        for(int i= 0;i<s.size();i++){
            if(s[i]=='('){
                bt.push(i);
                
            }
            else if(s[i]=='*'){
                st.push(i);
            }
            else {
                if(!bt.empty())bt.pop();
                else if(!st.empty())st.pop();
                else return false;
            }
        }
        while(!st.empty()&&!bt.empty()){
            if(st.top()>bt.top()){
                st.pop();
                bt.pop();
            }
            else return false;

        }
        
        return bt.empty();
    }
};