class Solution {
public:

    void dfs(vector<int>& nums, vector<vector<int>>& ans, int begin){
        if(begin>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[i],nums[begin]);
            dfs(nums,ans,begin+1);
            swap(nums[i],nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums,ans,0);
        return ans;
    }
};