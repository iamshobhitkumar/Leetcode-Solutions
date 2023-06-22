class Solution {
public:
    int solve(string& s1, string& s2,vector<vector<int>>& dp,int i, int j,int n){
        if(i==n||j==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int no = max(solve(s1,s2,dp,i+1,j,n),solve(s1,s2,dp,i,j+1,n));
        int yes = 0;
        if(s1[i]==s2[j]){
            yes = 1 + solve(s1,s2,dp,i+1,j+1,n);
        }
        return dp[i][j] = max(yes,no);
    }
    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        reverse(s2.begin(),s2.end());
        return n - solve(s,s2,dp,0,0,n);
    }
};