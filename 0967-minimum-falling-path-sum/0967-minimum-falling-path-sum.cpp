class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m){        if(i==n-1) return dp[i][j] = matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        vector<int> dircol = {-1,0,1};
        int ans =1e9;
        for(int a= 0;a<3;a++){
            int row = i+1;
            int col = j+dircol[a];
            if(row<n && col>=0 && col<m){
                ans = min(ans,solve(matrix,dp,row,col,n,m));
            }
        }
        return dp[i][j] = matrix[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int maxi = 1e9;
        for(int j=0;j<n;j++) dp[n-1][j] = matrix[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int ans =1e9;
                vector<int> dircol = {-1,0,1};
                for(int a= 0;a<3;a++){
                    int row = i+1;
                    int col = j+dircol[a];
                    if(col>=0 && col<m){
                        ans = min(ans,dp[row][col]);
                    }
                }
                dp[i][j] = matrix[i][j] + ans;
            }
        }
        for(int j=0;j<m;j++){
            maxi = min(maxi, dp[0][j]);
        }
        return maxi;
    }
};