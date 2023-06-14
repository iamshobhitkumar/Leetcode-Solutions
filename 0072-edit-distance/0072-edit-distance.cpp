class Solution {
public:

    int f(string word1, string word2,vector<vector<int>> dp, int i, int j){
        if(i<0)return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j] = f(word1,word2,dp,i-1,j-1);
        }
        else{
            return dp[i][j] = 1 + min(f(word1,word2,dp,i-1,j-1),min(f(word1,word2,dp,i-1,j),f(word1,word2,dp,i,j-1)));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};