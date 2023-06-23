class Solution {
public:
    bool solve(string s,vector<vector<int>>& dp, int i, int n, int count){
        if(count<0) return false;
        if(i==n){
            if(count == 0) return true;
            return false;
        }
        if(dp[i][count]!=-1) return dp[i][count];
        if(s[i]=='(')
            return dp[i][count] = solve(s,dp,i+1,n,count+1);
        else if(s[i] == ')'){
            if(count<=0) return false;
            return dp[i][count] = solve(s,dp,i+1,n,count-1);
        }
        else{
            return dp[i][count] = solve(s,dp,i+1,n,count+1) || solve(s,dp,i+1,n,count-1) || solve(s,dp,i+1,n,count);
        }
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(101,-1));
        return solve(s,dp,0,n,0);
    }
};