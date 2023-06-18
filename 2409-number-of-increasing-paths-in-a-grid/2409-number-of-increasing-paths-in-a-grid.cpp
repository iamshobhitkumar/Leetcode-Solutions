class Solution {
public:
    int mod = 1e9+7;
    int f(vector<vector<int>>& grid, vector<vector<long>>& dp, int i, int j, int m, int n){
        if(dp[i][j]!=-1) return dp[i][j];
        vector<int> dir = {0,1,0,-1,0};
        long long ans=1;
        for(int d=0;d<4;d++){
            int x = i+dir[d], y=j+dir[d+1];
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y] > grid[i][j])
                ans = (ans+f(grid,dp,x,y,m,n))%mod;
        }
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long>> dp(m,vector<long>(n,-1));
        long long sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum = (sum+ f(grid,dp,i,j,m,n))%mod;
            }
        }
        return sum;
    }
};