class Solution {
public:
 int gcd(int a,int b){
        while(b!=0){
         int temp=b;
              b=a%b;
          a=temp;
        }
 return a;
 }

 int maxValidSplits(vector<int>& nums){
    int ans=0;
     int n=nums.size();

    for(int i=0;i<=n;i++){
       vector<int> arr;

        if(i==n){
          arr=nums;
        }
        else{
             for(int j=0;j<n;j++){
              if(j!=i)
                   arr.push_back(nums[j]);
             }
        }

       int m=arr.size();
       if(m<2) continue;

        vector<int> suf(m);
        suf[m-1]=arr[m-1];

       for(int j=m-2;j>=0;j--){
          suf[j]=gcd(arr[j],suf[j+1]);
       }

       int cnt=0;
       int curs=0;

        for(int k=0;k<m-1;k++){
          curs=gcd(curs,arr[k]);
          int r=suf[k+1];

           if(curs==r)
             cnt++;
        }

       ans=max(ans,cnt);
    }

    return ans;
 }
};