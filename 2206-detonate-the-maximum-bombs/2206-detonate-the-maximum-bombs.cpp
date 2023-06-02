#define ll long long
class Solution {
public:
    void DFS(vector<vector<int>>& graph,vector<bool>& visited,int &i, int& c){
        visited[i] = true;
        c++;
        for(int index =0;index<graph[i].size();index++){
            if(!visited[graph[i][index]])
                DFS(graph,visited,graph[i][index],c);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            ll x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j = 0;j<n;j++){
                if(i!=j){
                    ll x2 = abs(x1- bombs[j][0]);
                    ll y2 = abs(y1-bombs[j][1]);
                    if(sqrt(x2*x2+y2*y2)<=r1){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int c =0;
            vector<bool> visited(n,false);
            DFS(graph,visited,i,c);
            ans = max(ans,c);
        }
        return ans;
    }
};