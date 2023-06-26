class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>& colour, int node){
        for(auto it: graph[node]){
            if(colour[it]==colour[node])return false;
            else if(colour[it]==0){
                colour[it] = -colour[node];
                if(!dfs(graph,colour,it)) return false;
            }
        }
        return true;
    }
    bool bfs(vector<vector<int>>& graph, vector<int>& colour, int node){
        queue<int> q;
        q.push(node);
        colour[node] = 1;
        while(q.size()){
            int node= q.front();
            q.pop();
            for(auto it: graph[node]){
                if(colour[it] == colour[node]) return false;
                else if(colour[it]==0){
                    colour[it] = -colour[node];
                    q.push(it);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n,0);
        for(int i=0;i<n;i++){
            if(colour[i]==0){
                colour[i] = 1;
                if(!dfs(graph, colour,i)) return false;
            }
        }
        return true;
    }
};