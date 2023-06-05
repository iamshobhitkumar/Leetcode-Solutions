class Solution {
public:
    int f(string &t, string &s,vector<vector<int>>& dp, int index1, int index2){
        if(index2<0) return 1;
        if(index1<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(t[index1] == s[index2]){
            return dp[index1][index2]= f(t,s,dp,index1-1,index2-1) + f(t,s,dp,index1-1,index2);
        }
        return dp[index1][index2] = f(t,s,dp,index1-1,index2);
    }
    int numDistinct(string s, string t) {
        int ls = s.size();
        int lt = t.size();
        vector<vector<int>> dp(ls,vector<int>(lt,-1));
        return f(s,t,dp,ls-1,lt-1);
    }
};