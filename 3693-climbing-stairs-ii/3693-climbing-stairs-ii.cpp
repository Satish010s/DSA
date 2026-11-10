class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long>dp(n+1,LLONG_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int stepCost = costs[i - 1]; 
            if(i-1>=0 && dp[i-1]!=LLONG_MAX) dp[i]=min(dp[i],dp[i-1]+stepCost+1);
            if(i-2>=0 && dp[i-2]!=LLONG_MAX) dp[i]=min(dp[i],dp[i-2]+stepCost+4);
            if(i-3>=0 && dp[i-3]!=LLONG_MAX) dp[i]=min(dp[i],dp[i-3]+stepCost+9);
        }
        return (int)dp[n];
    }
};