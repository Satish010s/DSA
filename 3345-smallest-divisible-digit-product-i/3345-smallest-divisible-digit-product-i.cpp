class Solution {

    int getProduct(int n,int t){
        int product=1;
        while(n!=0){
            int rem=n%10;
            product*=rem;
            n/=10;
        }
        return product;
    }
public:
    int smallestNumber(int n, int t) {
       while(getProduct(n,t)%t!=0){
        n++;
       }
       return n;
    }
};