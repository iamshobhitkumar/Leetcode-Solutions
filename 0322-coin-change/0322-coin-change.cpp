class Solution {
public:

    int solve(vector<int>& coins,vector<vector<int>>& dp, int i, int amount){
        if(amount == 0) return 0;
        if(i<0){
            if(amount==0) return 0;
            return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTake = solve(coins,dp, i-1,amount);
        int take = 1e9;
        if(coins[i]<=amount) take = 1+ solve(coins,dp,i,amount-coins[i]);
        return dp[i][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(coins,dp, n-1,amount);
        if(ans == 1e9) return -1;
        return ans;
    }
};