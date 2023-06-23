class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 1e9;
        vector<int> prev(n,0),curr(n,0);
        for(int j=0;j<n;j++) prev[j] = matrix[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int ans =1e9;
                vector<int> dircol = {-1,0,1};
                for(int a= 0;a<3;a++){
                    int row = i+1;
                    int col = j+dircol[a];
                    if(col>=0 && col<m){
                        ans = min(ans,prev[col]);
                    }
                }
                curr[j] = matrix[i][j] + ans;
            }
            prev = curr;
        }
        for(int j=0;j<m;j++){
            maxi = min(maxi, prev[j]);
        }
        return maxi;
    }
};