class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j){
        if(i==0 && j==0){
            if(grid[i][j] == 1) return 0;
            return 1;
        }
        int left = 0;
        if(j-1>=0)left = solve(grid,i,j-1);
        int up = 0;
        if(i-1>=0) up = solve(grid,i-1,j);
        return left + up;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]!=1)dp[i][0] = dp[i-1][0];
        }
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]!=1) dp[0][j] = dp[0][j-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] =0;
                    continue;
                }
                int right = 0, down = 0;
                if(j-1>=0) right = dp[i][j-1];
                if(i-1>=0) down = dp[i-1][j];
                dp[i][j] = right + down;
            }
        }
        return dp[m-1][n-1];
    }
};