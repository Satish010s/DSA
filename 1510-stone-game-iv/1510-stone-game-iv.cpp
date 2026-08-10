class Solution {
  
    private:
    bool solve(int num,int idx,int p,  vector<vector<int>>&dp){
       
        if (num==0){
            return false; 
        }
       if (dp[num][p] != -1) return dp[num][p];
        for(int i=idx;i*i<=num;i++){
            int nextPlayer=(p==0) ?1:0;
            if(!solve(num-i*i,1,nextPlayer,dp)){
                 return dp[num][p]=1;
            }
        }
        return dp[num][p]=0;
    }
public:
    bool winnerSquareGame(int n) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
      return solve(n,1,0,dp);
    }
};