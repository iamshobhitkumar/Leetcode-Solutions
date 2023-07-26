class Solution {
public:

    int solve(vector<int>& nums,vector<vector<int>>& dp, int i, int target){
        if(i==0){
            if(target==0 && nums[i]==0) return 2;
            if(target==0 || target==nums[i]) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notTake = solve(nums,dp,i-1,target);
        int take = 0;
        if(nums[i]<=target) take = solve(nums,dp,i-1,target-nums[i]);
        return dp[i][target] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(auto it: nums)
            sum += it;
        if(target > sum) return 0;
        if(abs(sum-target)%2) return 0;
        int t = abs(sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(1001,-1));
        return solve(nums,dp,nums.size()-1,t);
    }
};