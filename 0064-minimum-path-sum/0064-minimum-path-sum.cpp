class Solution {
    int m,n;
    private:

    int minimumSum(vector<vector<int>>& grid,int i,int j, vector<vector<int>>&dp){
          
        if(i>=m || j>=n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return grid[i][j];

        int currSum=grid[i][j];
        int left=minimumSum(grid,i,j+1,dp);
         int right=minimumSum(grid,i+1,j,dp);
         return dp[i][j]=currSum+min(left,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
      
        m=grid.size();
        n=grid[0].size();
          vector<vector<int>>dp(m,vector<int>(n,-1));
       return  minimumSum(grid,0,0,dp);
    }
};