class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int size = stoneValue.size();
        vector<int> dp(size+1,0);
        dp[size] = 0;
        vector<int> sufsum(size+1,0);
        for(int i= size-1;i>=0;i--){
            sufsum[i] = sufsum[i+1]+stoneValue[i];
        }
        for(int i= size-1;i>=0;i--){
            dp[i] = stoneValue[i] + sufsum[i+1]-dp[i+1];
            for(int k =i+1;k<i+3 && k<size;k++){
                dp[i] = max(dp[i],sufsum[i]-dp[k+1]);
            }
        }
        if(dp[0]*2 == sufsum[0])
            return "Tie";
        else if(dp[0]*2 > sufsum[0])
            return "Alice";
        return "Bob";
    }
};