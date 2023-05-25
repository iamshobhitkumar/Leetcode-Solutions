class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k ==0 || n >=k+maxPts)
            return 1.0;
        vector<double> dp(n+1);
        dp[0] = 1.0;
        double ma = 1.0;
        double ans = 0.0;

        for(int i=1;i<k;i++){
            dp[i] = ma/maxPts;
            ma +=dp[i];
            if(i-maxPts >=0){
                ma -= dp[i-maxPts];
            }
        }

        for(int i=k;i<=n;i++){
            dp[i] = ma/maxPts;
            ans+= dp[i];
            if(i-maxPts>=0)
                ma -=  dp[i-maxPts];
        }
        return ans;
    }
};