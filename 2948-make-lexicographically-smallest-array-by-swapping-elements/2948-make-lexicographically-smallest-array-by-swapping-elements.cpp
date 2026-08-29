
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& a, int l) {
        vector<pair<int,int>> v;
        int n=a.size();

        for(int i=0;i<n;i++)
            v.push_back({a[i],i});

        sort(v.begin(),v.end());

        int s=0;
        while(s<n){
            int e=s;

            while(e+1<n && v[e+1].first-v[e].first<=l)
                e++;

            vector<int> x;
            for(int i=s;i<=e;i++)
                x.push_back(v[i].second);

            sort(x.begin(),x.end());

            for(int i=0;i<=e-s;i++)
                a[x[i]]=v[s+i].first;

            s=e+1;
        }

        return a;
    }
};

