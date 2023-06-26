class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n==1){
            if(amount ==0 ) return 0;
            if(amount%coins[0]==0) return amount/coins[0];
            return -1;
        }
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i= 1;i<=amount;i++){
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int i=1;i<n;i++){
            for(int j = 0; j<=amount;j++){
                int notTake = dp[i-1][j];
                int take = 1e9;
                if(coins[i]<=j) take = 1+ dp[i][j-coins[i]];
                dp[i][j] = min(take,notTake);
            }
        }
        if(dp[n-1][amount] == 1e9) return -1;
        return dp[n-1][amount];
    }
};