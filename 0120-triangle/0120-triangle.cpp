class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int mini = 1e9;
        dp[0][0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>i)continue;
                int up = 1e9;
                if(j<=i-1) up = dp[i-1][j];
                int left = 1e9;
                if(j-1>=0) left = dp[i-1][j-1];
                dp[i][j] = triangle[i][j] + min(up,left);
            }
        }
        for(int i=0;i<n;i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini;
    }
};