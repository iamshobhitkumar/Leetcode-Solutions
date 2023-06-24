class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> p, n;
        for(auto it: nums){
            if(it>0) p.push_back(it);
            else n.push_back(it);
        }
        int i=0, j=0;
        ans.push_back(p[i++]);
        while(i<p.size() && j<n.size()){
            if(ans[ans.size()-1]>0){
                ans.push_back(n[j++]);
            }
            else ans.push_back(p[i++]);
        }
        while(i<p.size()) ans.push_back(p[i++]);
        while(j<n.size()) ans.push_back(n[j++]);
        return ans;
    }
};