class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int end=123;
        long long   sum=0;
        for(int  i=0;i<n;i++){
            sum+=((end-s[i]))*(i+1);

        }
        return sum;
    }
};