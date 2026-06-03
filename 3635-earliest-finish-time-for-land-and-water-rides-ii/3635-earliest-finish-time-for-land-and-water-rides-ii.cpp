class Solution {
public:
int ans(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd){
    int l = INT_MAX;
        for(int i = 0;i<lst.size();i++){
            l = min(l,lst[i]+ld[i]);
        }
        int w = INT_MAX;
        for(int i = 0;i<wst.size();i++){
            w = min(w,max(l,wst[i])+wd[i]);
        }
        return w;
}
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int land = ans(lst,ld,wst,wd);
        int water = ans(wst,wd,lst,ld);
        int res = min(land,water);
        return res;
    }
};