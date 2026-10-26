#include <vector>
using namespace std;

class Solution {
    long long  dfs(vector<vector<int>>& grid, int k, vector<vector<int>>& visited, int i, int j){ 
        int n=grid.size();
        int m=grid[0].size();
        visited[i][j]=1;
        long long  sum=grid[i][j];
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int d=0;d<4;d++){
            int nrow=i+delRow[d];
            int ncol=j+delCol[d];
    
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]!=0){
                sum+=dfs(grid,k,visited,nrow,ncol); 
            }
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]!=0){
                    long long  isLandSum=dfs(grid,k,visited,i,j);
                    if(isLandSum % k==0){
                         ans++;
                    }
                }
            }
        }
        return ans;
    }
};
