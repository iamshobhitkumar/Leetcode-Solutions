class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int ans = 1e9;
       int i=0, j=0;
       int n = nums.size();
       int sum = 0;
       while(j<n){
           sum+=nums[j];
           while(i<=j && sum >= target){
               ans = min(ans,j-i+1);
               sum-=nums[i];
               i++;
           }
           j++;
       }
       return ans==1e9?0:ans;
    }
};