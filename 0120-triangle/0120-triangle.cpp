class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,0),curr(n,0);
        int mini = 1e9;
        prev[0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>i)continue;
                int up = 1e9;
                if(j<=i-1) up = prev[j];
                int left = 1e9;
                if(j-1>=0) left = prev[j-1];
                curr[j] = triangle[i][j] + min(up,left);
            }
            prev = curr;
        }
        for(int i=0;i<n;i++){
            mini = min(mini,prev[i]);
        }
        return mini;
    }
};