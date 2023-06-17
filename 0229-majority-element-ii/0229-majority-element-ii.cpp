class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = nums.size()/3;
        unordered_map<int,int> m;
        for(auto it: nums) m[it]++;
        vector<int> v;
        for(auto it: m){
            if(it.second > count) v.push_back(it.first);
        }
        return v;
    }
};