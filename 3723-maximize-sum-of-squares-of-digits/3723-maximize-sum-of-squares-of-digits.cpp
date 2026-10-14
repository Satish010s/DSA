class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if(sum > num*9) return "";
        for(int i=1;i<=num;i++){
            int value=min(9,sum);
            ans += char('0'+value);
            sum-=value;
        }
        return ans;
    }
};