class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        while(true){
            if(a+b+c==n)return true;
            else if(a+b+c>n)return false;
            int temp = c;
            a=b;
            b=temp;
            c= a+b;
            
            
            
        }
        return false;
    }
};