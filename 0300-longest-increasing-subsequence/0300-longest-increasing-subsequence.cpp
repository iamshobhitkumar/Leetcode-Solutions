class Solution {
public:

    int solve(vector<int>& nums, vector<vector<int>>& dp, int i, int n, int prev){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int notTake = solve(nums,dp,i+1,n,prev);
        int take= 0;
        if(prev == -1 || nums[i]>nums[prev]) take = 1 + solve(nums,dp,i+1,n,i);
        return dp[i][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,dp, 0, n, -1);
    }
};