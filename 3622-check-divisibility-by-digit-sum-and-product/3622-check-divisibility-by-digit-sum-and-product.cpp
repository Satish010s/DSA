class Solution {
public:
    bool checkDivisibility(int n) {
        int  N=n;
        int sum=0;
        int pro=1;
        while(n!=0){
            int rem=n%10;
            sum+=rem;
            pro*=rem;
            n/=10;
        }
       int nextSum=sum+pro;
       if(nextSum==0) return false;
       if(N%nextSum!=0) return false;
       return true;
    }
};