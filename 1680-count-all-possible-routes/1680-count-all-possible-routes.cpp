class Solution {
public:
    int mod = 1e9+7;
    int solve(vector<int>& locations,vector<vector<int>>& dp, int start, int finish, int fuel){
        int ans = 0;
        if(start == finish){
            if(fuel<=0) return 1;
            else ans++;
        }
        if(fuel<=0) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        for(int i=0;i<locations.size();i++){
            int curr = abs(locations[i]-locations[start]);
            if(start!=i && curr<=fuel){
                ans = (ans + solve(locations,dp, i, finish, fuel - curr))%mod;
            }
        }
        return dp[start][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1,-1));
        return solve(locations,dp, start, finish, fuel);
    }
};