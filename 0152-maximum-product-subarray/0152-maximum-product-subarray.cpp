class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> mindp(n),maxdp(n);
        int ans = nums[0];
        mindp[0] = maxdp[0] = ans;
        for(int i=1;i<n;i++){
            mindp[i] = min(nums[i],nums[i]*(nums[i]>=0?mindp[i-1]:maxdp[i-1]));
            maxdp[i] = max(nums[i],nums[i]*(nums[i]>=0?maxdp[i-1]:mindp[i-1]));
            ans = max(maxdp[i],ans);
        }
        return ans;
    }
};