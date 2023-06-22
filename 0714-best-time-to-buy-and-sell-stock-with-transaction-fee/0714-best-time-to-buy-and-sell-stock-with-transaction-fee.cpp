class Solution {
public:

    int solve(vector<int>& prices, vector<vector<int>>& dp,int index, int n, int buy,int fee){
        if(index==n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int take = 0, notTake = 0;
        if(buy){
            take = max(-prices[index] + solve(prices, dp, index+1,n,0,fee),solve(prices,dp,index+1,n,1,fee));
        }
        else
            notTake = max(prices[index] + solve(prices,dp,index+1,n,1,fee)-fee, solve(prices,dp,index+1,n,0,fee));
        return dp[index][buy] = max(take,notTake);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices, dp, 0,n,1,fee);
    }
};