class Solution {
public:
    int f(vector<int>& nums,vector<vector<int>>& dp, int i, int prev,int n){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int notTake = f(nums,dp,i+1,prev,n);
        int take = INT_MIN;
        if(prev==-1 || nums[i] > nums[prev]){
            take = 1 + f(nums,dp,i+1,i,n);
        }
        return dp[i][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // if(n==1) return 1;
        // vector<int>dp(n,1);
        // int ans =0;
        // for(int i=0;i<n;i++){
        //     for(int prev = 0;prev<i;prev++){
        //         if(nums[i] > nums[prev] && 1+dp[prev] > dp[i]){
        //             dp[i] = 1+dp[prev];
        //         }
        //         ans = max(dp[i],ans);
        //     }
        // }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(nums,dp,0,-1,n);
    }
};