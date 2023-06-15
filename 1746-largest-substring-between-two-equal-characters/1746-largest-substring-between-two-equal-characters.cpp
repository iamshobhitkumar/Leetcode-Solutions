class Solution {
public:
    int f(string& s, string& s2,vector<vector<int>>& dp, int i, int j,int n){
        if(i==n || j==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == s2[j]) return dp[i][j] = (n-j-i-2);
        return dp[i][j] = max(f(s,s2,dp,i+1,j,n),f(s,s2,dp,i,j+1,n));
    }
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        string s2 = s;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        reverse(s2.begin(),s2.end());
        return f(s,s2,dp,0,0,n);
    }
};