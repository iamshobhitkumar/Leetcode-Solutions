class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(m%2 == 0 && nums[m] == nums[m+1] || m%2 && nums[m-1] == nums[m])
                l = m+1;
            else
                r = m;
        }
        return nums[l];
    }
};