class Solution {
public:
    int f(vector<vector<int>>& dp, int i, int j, int m,int n){
        if(i==m-1 || j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = f(dp,i+1,j,m,n) + f(dp,i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(dp,0,0,m,n);
    }
};