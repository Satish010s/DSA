class Solution {
    private:
     int getBestScore(int i,int m,vector<int>&piles,vector<int>&suffixSum,   vector<vector<int>>&dp){
        if(i>=piles.size()) return 0;
        if(i+2*m>=piles.size()) return suffixSum[i];
        if(dp[i][m]!=-1) return dp[i][m];
        int maxScore=0;
        for(int X=1;X<=2*m;X++){
           int opponent_score = getBestScore(i + X, max(m, X),piles,suffixSum,dp);
            
            // Your score is the total remaining stones minus the opponent's best score
            int current_score = suffixSum[i] - opponent_score;
            
            maxScore = max(maxScore, current_score);
        }
          return dp[i][m] = maxScore;
     }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int>suffixSum(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]+piles[i];
        }
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return getBestScore(0,1,piles,suffixSum,dp);
    }
};