class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n,0), curr(n,0);
        prev[0] = grid[0][0];
        for(int j=1;j<n;j++) prev[j] = grid[0][j]+prev[j-1];
        for(int i=1;i<m;i++){
            curr[0] = grid[i][0] + prev[0];
            for(int j=1;j<n;j++){
                int up = prev[j], left = curr[j-1];
                curr[j] = grid[i][j] + min(up,left);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};