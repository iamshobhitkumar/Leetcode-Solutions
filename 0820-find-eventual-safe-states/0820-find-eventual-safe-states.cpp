class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& pathVisited, int node){
        visited[node] = true;
        pathVisited[node] = 1;
        for(auto it: graph[node]){
            if(!visited[it]){
                dfs(graph, visited, pathVisited, it);
                if(pathVisited[it] == -1){
                    pathVisited[node] = -1;
                    return;
                }
            }
            else{
                if(pathVisited[it] == 1){
                    pathVisited[it] = -1;
                    pathVisited[node] = -1;
                    return;
                }
                else if(pathVisited[it] == -1){
                    pathVisited[node] = -1;
                    return;
                }
            }
        }
        if(pathVisited[node]!=-1)
            pathVisited[node] = 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<int> pathVisited(n,0);
        vector<int> v;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph,visited, pathVisited, i);
            }
        }
        for(int i=0;i<n;i++){
            if(pathVisited[i]!=-1) v.push_back(i);
        }
        return v;
    }
};