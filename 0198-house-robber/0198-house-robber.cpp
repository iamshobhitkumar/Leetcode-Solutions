class Solution {
public:
    int f(vector<int>& nums, vector<int>& dp, int i){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i]+ f(nums,dp,i-2),f(nums,dp,i-1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        if(n==1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
                dp[i] = max(nums[i]+ dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};