class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";
        for(int i = 0;i<path.size();i++){
            if(i<path.size()&& path[i]!='/'){
                temp += path[i];
            }
            else{
                if(temp==""||temp=="."){
                    temp = "";
                }
                else if(temp==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                    temp = "";
                }
                else {
                    st.push(temp);
                    temp = "";
                }
            }
        }
            if(temp==""||temp=="."){
                    temp = "";
                }
                else if(temp==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                    temp = "";
                }
                else {
                    st.push(temp);
                    temp = "";
                }
        path = "";
        while(!st.empty()){
            path = '/'+st.top()+path;
            st.pop();
        }
        if(path=="")return "/";
        return path;
    }
};