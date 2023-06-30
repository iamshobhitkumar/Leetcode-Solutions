class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n = image.size(), m = image[0].size();
        int c = image[sr][sc];
        if(c==color) return image;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(q.size()){
            auto it =  q.front();
            int row = it.first;
            int col = it.second;
            cout<<row<<" "<<col<<endl;
            q.pop();
            vector<int> dx = {-1,0,1,0};
            vector<int> dy = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow>=0 && ncol >=0 && nrow< n && ncol < m && image[nrow][ncol] == c){
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};