class Solution {
public:

    bool dfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, int node){
        visited[node] = true;
        pathVisited[node] = true;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(!dfs(adj, visited,pathVisited, it)) return false;
            }
            else{
                if(pathVisited[it]) return false;
            }
            
        }
        pathVisited[node] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses; i++){
            vector<int> visited(numCourses, false), pathVisited(numCourses, false);
            if(!dfs(adj,visited,pathVisited,i)) return false;
        }
        return true;
    }
};