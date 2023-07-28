class Solution {
public:

    int takeStone(bool Player, int l, int h, vector<int>& nums,vector<vector<int>>& dp)
    {
        if(l>h) return -1;
        if(l==h) return nums[l];
        if(dp[l][h]!=-1) return dp[l][h];
        if(Player)    
            dp[l][h] = max(nums[l]+takeStone(!Player,l+1,h,nums,dp),nums[h]+takeStone(!Player,l,h-1,nums,dp));
        else
            dp[l][h] = min(-nums[l]+takeStone(!Player,l+1,h,nums,dp),-nums[h]+takeStone(!Player,l,h-1,nums,dp));

        return dp[l][h];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return takeStone(true,0,n-1,nums,dp)>=0;
    }
};