class Solution {
public:
    bool f(vector<int>& nums,vector<int>&dp, int i, int n){
        if(i==n-1) return true;
        if(i>n-1) return false;
        if(dp[i]!=-1) return dp[i];
        bool flag = false;
        for(int jump=1;jump<=nums[i];jump++){
            flag = f(nums,dp,i+jump,n);
            if(flag)
                break;
        }
        return dp[i] = flag;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(nums,dp,0,n);
    }
};