class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i: nums){
            m[i]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>> q;
        for(auto it = m.begin();it!=m.end();it++){
            q.push(make_pair(it->second, it->first));
            if(q.size() > (int)m.size()-k){
                ans.push_back(q.top().second);
                q.pop();
            }
        }
        return ans;
    }
};