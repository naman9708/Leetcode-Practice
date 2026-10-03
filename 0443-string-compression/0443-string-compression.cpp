class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ans = 0;

        while(i < chars.size()){
            char ch = chars[i];
            int count = 0;

            while(i < chars.size() &&chars[i] == ch){
                i++;
                count++;
            }

            chars[ans] = ch;
            ans++;

            if(count > 1){
                string s = to_string(count);

                for(char c : s){
                    chars[ans] = c;
                    ans++;
                }
            }
        }

        return ans;
    }
};