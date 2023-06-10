class Solution {
public:
    int f(vector<int>& nums, vector<int>& dp, int i){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i]+ f(nums,dp,i-2),f(nums,dp,i-1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(nums,dp,n-1);
    }
};