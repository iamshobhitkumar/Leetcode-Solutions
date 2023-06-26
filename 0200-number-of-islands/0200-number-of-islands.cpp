class Solution {
public:
    void remove(vector<vector<char>>& grid,int i,int j,int m,int n){
        if(i<0 || j<0 || i>m-1 ||j>n-1 || grid[i][j] == '0')
            return;
        grid[i][j]='0';
        remove(grid,i+1,j,m,n);
        remove(grid,i-1,j,m,n);
        remove(grid,i,j+1,m,n);
        remove(grid,i,j-1,m,n);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    ans++;
                    remove(grid,i,j,grid.size(),grid[0].size());
                }
            }
        }
        return ans;
    }
};