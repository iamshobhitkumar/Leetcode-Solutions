class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int>> dp(len+1, vector<int>(len+1,0));
        vector<int> sufsum(len+1, 0);
        for(int i= len-1; i>=0;i--){
            sufsum[i] = sufsum[i+1]+piles[i];
        }
        for(int i=0;i<=len;i++)
            dp[i][len] = sufsum[i];
        for(int i=len-1;i>=0;i--){
            for(int j = len-1;j>=1;j--){
                for(int x = 1;x<=2*j && i+x<=len;x++){
                    dp[i][j] = max(dp[i][j],sufsum[i]-dp[i+x][max(j,x)]);
                }
            }
        }
        return dp[0][1];
    }
};