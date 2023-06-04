class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited,int i){
        visited[i] = true;
        vector<int> v = graph[i];
        for(int index =0; index<v.size();index++){
            if( v[index] && !visited[index])
                dfs(graph,visited,index);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i])
                continue;
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && !visited[i]){
                    dfs(isConnected,visited,i);
                    count++;
                }
            }
        }
        return count;
    }
};