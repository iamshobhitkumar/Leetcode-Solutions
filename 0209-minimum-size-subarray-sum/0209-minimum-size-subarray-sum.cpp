class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i=0, j=0;
        int curr = 0;
        while(j<nums.size()){
            curr+=nums[j++];
            while(curr>=target){
                ans = min(ans,j-i);
                curr-=nums[i];
                i++;
            }
        }
        return ans==INT_MAX? 0 : ans;
    }
};