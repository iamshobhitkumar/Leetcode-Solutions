class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> prob(n,0);
        priority_queue<pair<double,int>> q;
        prob[start] = 1;
        q.push({1,start});
        while(q.size()){
            int node = q.top().second;
            double pro = q.top().first;
            q.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                double edgeProb = it.second;
                if(pro*edgeProb > prob[adjNode]){
                    prob[adjNode] = pro*edgeProb;
                    q.push({prob[adjNode], adjNode});
                }
            }
        }
        return prob[end];
    }
};