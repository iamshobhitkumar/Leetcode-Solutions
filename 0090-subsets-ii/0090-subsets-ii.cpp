class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans,vector<int> v, set<vector<int>>& s, int i, int n){
        if(i==n) return;
        vector<int> temp = v;
        sort(temp.begin(),temp.end());
        if(s.find(temp)==s.end()){
            ans.push_back(v);
            s.insert(temp);
        }
        solve(nums,ans,v,s,i+1,n);
        v.push_back(nums[i]);
        temp = v;
        sort(temp.begin(),temp.end());
        if(s.find(temp)==s.end()){
            ans.push_back(v);
            s.insert(temp);
        }
        solve(nums,ans,v,s,i+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> v;
        solve(nums,ans,v,s,0,nums.size());
        return ans;
    }
};