class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size()==2){
            return cost[1] + cost[0];
        }
        if(cost.size()==1){
            return cost[0];
        }
        sort(cost.begin(),cost.end());
        int n = 0;
        int i = cost.size()-1;
        while(i>=2)
        {
            n += cost[i]+cost[i-1];
            i-=3;
        }
        while(i>=0){
            n += cost[i];
            i--;
        }
        // if(i)
        return n;
    }
};