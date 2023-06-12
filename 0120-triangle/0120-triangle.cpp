class Solution {
public:
    int f(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j){
        if(i==0){
            return triangle[0][0];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up = 1e9;
        cout<<"Up Call for "<<i-1<<" "<<j<<endl;
        if(j<=i-1) up =  f(triangle, dp, i-1,j);
        int left = 1e9;
        cout<<"Left Call for "<<i-1<<" "<<j-1<<endl;
        if(j-1>=0) left = f(triangle, dp,i-1, j-1);
        return dp[i][j] = triangle[i][j] + min(up,left);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int mini = 1e9;
        for(int i=0;i<n;i++){
            mini = min(mini,f(triangle,dp,n-1,i));
            cout<<"Loop for "<<i<<endl;
        }
        return mini;
    }
};