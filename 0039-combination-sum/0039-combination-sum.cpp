class Solution {
public:

    void solve(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& v, int i, int n,int sum, int target){
        if(sum == target){
            ans.push_back(v);
            return;
        }
        if(sum > target || i==n) return;
        v.push_back(candidates[i]);
        solve(candidates,ans,v,i,n,sum + candidates[i],target);
        v.pop_back();
        solve(candidates,ans,v,i+1,n,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates, ans, v, 0, candidates.size(), 0, target);
        return ans;
    }
};