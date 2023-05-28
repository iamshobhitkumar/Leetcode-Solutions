class Solution {
public:
    int solve(vector<int>& cuts,vector<vector<int>>& dp, int n, int l, int r){
        if(r-l == 1 || l >= r)
            return 0;
        if(dp[l][r]!= -1)
            return dp[l][r];
        int mi = INT_MAX;
        for(int i = l+1;i<r;i++){
                mi = min(mi,(cuts[r]-cuts[l]) + solve(cuts,dp,n,l,i)+solve(cuts,dp,n,i,r));
        }
        return dp[l][r] = mi;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int size = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(102,vector<int>(102, -1));
        return solve(cuts,dp,size,0,size-1);
    }
};