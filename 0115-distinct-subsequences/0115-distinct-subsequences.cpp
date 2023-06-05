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
        vector<vector<double>> dp(ls+1,vector<double>(lt+1,0));
        for(int i=0;i<=ls;i++) dp[i][0] = 1;
        for(int index1=1;index1<=ls;index1++){
            for(int index2 = 1;index2<=lt;index2++){
                if(s[index1-1] == t[index2-1]){
                    dp[index1][index2]= dp[index1-1][index2-1] + dp[index1-1][index2];
                }
                else dp[index1][index2] = dp[index1-1][index2];
            }
        }
        return (int)dp[ls][lt];
    }
};