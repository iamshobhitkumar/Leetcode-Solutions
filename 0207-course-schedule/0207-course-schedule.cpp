class Solution {
public:

    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited, int node){
        visited[node] = true;
        pathVisited[node] = true;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfs(adj,visited,pathVisited, it))
                     return true;
            }
            else if(pathVisited[it]) return true;
        }
        pathVisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(numCourses, false), pathVisited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(adj, visited, pathVisited, i))
                    return false;
            }
        }
        return true;
    }
};