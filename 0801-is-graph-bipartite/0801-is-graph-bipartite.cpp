class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n);
        queue<int> q;

        for(int i=0;i<n;i++){
            if(colour[i])
                continue;
            colour[i] = 1;
            q.push(i);
            while(q.size()){
                int cur = q.front();
                for(int i: graph[cur]){
                    if(!colour[i]){
                        colour[i] = -colour[cur];
                        q.push(i);
                    }
                    else if(colour[i]==colour[cur])
                        return false;
                }
                q.pop();
            }
        }
        return true;
    }
};