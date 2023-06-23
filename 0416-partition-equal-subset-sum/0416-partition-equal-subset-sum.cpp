class Solution {
public:
    bool solve(vector<int>& nums, vector<vector<int>>& dp, int i, int sum){
        if(sum==0) return true;
        if(i<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool notTake = solve(nums, dp, i-1, sum);
        bool take = false;
        if(nums[i]<=sum) take = solve(nums,dp,i-1,sum-nums[i]);
        return dp[i][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums) sum+=it;
        if(sum%2) return false;
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums,dp, nums.size()-1,target);
    }
};