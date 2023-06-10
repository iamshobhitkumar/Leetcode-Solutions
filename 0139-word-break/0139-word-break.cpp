class Solution {
public:
    bool f(string s, unordered_set<string>st,vector<int>& dp, int i, int n){
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        string temp = "";
        bool ans = false;
        for(int j = i;j<n;j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                ans = f(s,st,dp,j+1,n);
            }
            if(ans)
                break;
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i: wordDict){
            st.insert(i);
        }
        int n = s.size();
        vector<int> dp(n,-1);
        return f(s,st,dp,0,n);
        // vector<vector<bool>> dp(n+1,vector<bool>(n+1,0));
        // for(int i=1;i<=n;i++){
        //     string temp = "";
        //     for(int j=i;j<=n;j++){
        //         temp+=s[j];
        //         if(st.find(temp)!=st.end()){
        //             dp[i][j] = true && 
        //         }
        //     }
        // }
    }
};