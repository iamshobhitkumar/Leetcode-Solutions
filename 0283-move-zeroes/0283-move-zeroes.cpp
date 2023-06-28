class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0, j = 1;
        while(j<n){
            if(nums[i] == 0){
                while(j<n && nums[j]==0){
                    j++;
                }
                if(j<n)
                    swap(nums[i],nums[j]);
            }
            i++;
            j=i+1;
        }
    }
};