class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        grid[0][0] = 1;
        vector<vector<int>> directions = {{0,1},{1,0},{1,1},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};
        q.push({0,0});
        while(q.size()){
            auto curr= q.front();
            int x = curr.first, y = curr.second;
            if(x == n-1 && y == n-1) return grid[x][y];
            for(auto dir: directions){
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny] == 0){
                    grid[nx][ny] = grid[x][y] +1;
                    q.push({nx,ny});
                }
            }
            q.pop();
        }
        return -1;
    }
};