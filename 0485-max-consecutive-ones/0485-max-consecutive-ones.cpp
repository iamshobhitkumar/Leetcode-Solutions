class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l =0, r = 0;
        int ans = 0;
        while(l<=r && r<nums.size()){
            if(nums[r] !=1){
                ans = max(ans,r-l);
                l = r+1;
                r = l;
            }
            else{
                r++;
            }
        }
        return max(ans,r-l);
    }
};