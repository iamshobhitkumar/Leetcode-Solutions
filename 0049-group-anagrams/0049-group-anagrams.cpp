class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(temp);
        }
        for(auto it = m.begin();it!=m.end();it++){
            v.push_back(it->second);
        }
        return v;
    }
};