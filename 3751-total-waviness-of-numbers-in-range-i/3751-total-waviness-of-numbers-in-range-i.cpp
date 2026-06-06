class Solution {
public:
    int fun(int num){
        vector<int> arr;
        if(num<100)return 0;
        while(num!=0){
            arr.push_back(num%10);
            num/=10;
        }
        reverse(arr.begin(),arr.end());
        int cnt = 0;
        for(int i=1;i<arr.size()-1;i++){
            if((arr[i]>arr[i-1]&&arr[i]>arr[i+1])||(arr[i]<arr[i-1]&&arr[i]<arr[i+1])){
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        if(num1<100 && num2<100)return 0;
        long long ans = 0;
        for(int i = num1;i<=num2;i++){
            ans = ans + fun(i);
        }
        return ans;
    }
};