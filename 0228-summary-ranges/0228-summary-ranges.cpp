class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<string> v;
        int index = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]+1){
                continue;
            }
            else{
                string s;
                if(index!=i)
                    s = to_string(nums[index])+"->"+to_string(nums[i]);
                else s = to_string(nums[index]);
                v.push_back(s);
                index = i+1;
            }
        }
        string s;
        if(index!=nums.size()-1)
            s = to_string(nums[index])+"->"+to_string(nums[nums.size()-1]);
        else s = to_string(nums[index]);
        v.push_back(s);
        return v;
    }
};