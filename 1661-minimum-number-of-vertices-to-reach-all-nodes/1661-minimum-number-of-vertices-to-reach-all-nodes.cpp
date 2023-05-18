class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> dest;
        for(auto edge: edges){
            dest.insert(edge[1]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dest.find(i)==dest.end())
                ans.push_back(i);
        }
        return ans;
    }
};