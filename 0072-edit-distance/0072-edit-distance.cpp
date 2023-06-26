class Solution {
public:
    int solve(string s1, string s2,vector<vector<int>>& dp, int i, int j){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = solve(s1,s2,dp,i-1,j-1);
        else return dp[i][j] = 1+min(solve(s1,s2,dp,i,j-1),min(solve(s1,s2,dp,i-1,j),solve(s1,s2,dp,i-1,j-1)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(word1,word2,dp,n-1,m-1);
    }
};