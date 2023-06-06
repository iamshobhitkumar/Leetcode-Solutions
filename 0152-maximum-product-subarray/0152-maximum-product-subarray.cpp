class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minp = 1;
        int maxp = 1;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                swap(minp,maxp);
            }
            maxp = max(nums[i],nums[i]*maxp);
            minp = min(nums[i],nums[i]*minp);
            ans = max(ans,maxp);
        }
        return ans;
    }
};