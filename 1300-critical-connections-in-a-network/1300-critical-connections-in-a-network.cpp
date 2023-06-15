class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& low, vector<int>& time,vector<vector<int>>& bridges){
        visited[node] = true;
        time[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!visited[it]){
                dfs(it,node, adj, visited, low, time,bridges);
                low[node] = min(low[node],low[it]); 
                if(low[it]>time[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> low(n);
        vector<int> time(n);
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridges;
        vector<bool> visited(n,false);
        dfs(0,-1,adj,visited,low,time,bridges);
        return bridges;
    }
};