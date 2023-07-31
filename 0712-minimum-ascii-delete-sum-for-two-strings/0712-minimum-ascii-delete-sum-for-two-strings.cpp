class Solution {
public:
    int solve(string& s1, string& s2,vector<vector<int>>& dp, int i, int j){
        if(i<0){
            int ans = 0;
            while(j>=0){
                ans += int(s2[j--]);
            }
            return ans;
        }
        if(j<0){
            int ans = 0;
            while(i>=0){
                ans += int(s1[i--]);
            }
            return ans;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = solve(s1,s2,dp,i-1,j-1);
        return dp[i][j] = min(int(s1[i])+solve(s1,s2,dp,i-1,j),int(s2[j])+solve(s1,s2,dp,i,j-1));
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return solve(s1,s2,dp,s1.size()-1,s2.size()-1);
    }
};