class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int>dp(n,1);
        int ans =0;
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[i] > nums[prev] && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                }
                ans = max(dp[i],ans);
            }
        }
        return ans;
    }
};