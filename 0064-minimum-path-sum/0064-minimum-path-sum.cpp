class Solution {
public:

    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        if(i==0 && j==0) return grid[0][0];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = 1e9, left = 1e9;
        if(i-1>=0) up = solve(grid,dp,i-1,j);
        if(j-1>=0) left = solve(grid,dp,i,j-1);
        return dp[i][j] = grid[i][j] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(grid, dp,m-1,n-1);
    }
};