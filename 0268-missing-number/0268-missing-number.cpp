class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            maxi = max(maxi, nums[i]);
            s.insert(nums[i]);
        }
        for(int i=0;i<=maxi;i++){
            if(s.find(i)==s.end()) return i;
        }
        return maxi+1;
    }
};