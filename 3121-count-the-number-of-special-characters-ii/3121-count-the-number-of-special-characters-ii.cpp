class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> vis(26,-1), visi(26,-1);
        for(int i = 0;i<word.size();i++){
            if(word[i]>='a'&&word[i]<='z'){
                vis[word[i]-'a'] = i;
            }
            else if(word[i]>='A'&& word[i]<='Z'){
                if(visi[word[i]-'A']==-1)
                visi[word[i]-'A'] = i;
            }

        }
        int cnt = 0;
        for(int j = 0;j<26;j++){
                if(vis[j]!=-1&&visi[j]!=-1&&vis[j]<visi[j])cnt++;
            }
        return cnt;
    }
};