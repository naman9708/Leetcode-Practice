class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int d = 0;
        for(int i = 0;i<seq.size();i++){
            if(seq[i]=='('){
                d++;
                ans.push_back(d%2);
            }
            else if(seq[i]==')'){
                ans.push_back(d%2);
                d--;
            }
        }
        return ans;
    }
};