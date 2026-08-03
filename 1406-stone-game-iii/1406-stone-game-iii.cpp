class Solution {
    int solve(int i, vector<int>&suffixSum , vector<int>&dp,int n){
        
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxScore=-1e9;
        
        for(int x=1;x<=3;x++){
            if(i+x<=n){
            int opponentStones=solve(i+x,suffixSum,dp,n);
            int currentStones=suffixSum[i]-opponentStones;
            maxScore=max(maxScore,currentStones);
            }
        }
        return dp[i]=maxScore;

    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>suffixSum(n+1,0);
        //memo
        vector<int>dp(n,-1);
        for(int i=n-1;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]+stoneValue[i];
        }
        int Alice=solve(0,suffixSum,dp,n);
        int total_Score=suffixSum[0];
        int bob=total_Score-Alice;
        if(Alice>bob) return "Alice";
        if(Alice<bob) return "Bob";

        return "Tie";
    }
};