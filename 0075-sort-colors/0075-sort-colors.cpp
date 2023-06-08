class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h=n-1, m=l+1;
        int i=0;
        int c0=0,c1=0,c2 =0;
        while(i<n){
            if(nums[i]==0) c0++;
            if(nums[i]==1) c1++;
            else c2++;
            i++;
        }
        i=0;
        while(c0-- && i<n){
            nums[i++] = 0;
        }
        while(c1-- && i<n) nums[i++] = 1;
        while(c2-- && i<n) nums[i++] = 2;
        // while(i<n && m<=h){
        //     if(nums[i] ==0){
        //         swap(nums[i],nums[l]);
        //         if(i==l) i++;
        //         l++;
        //         m++;
        //     }
        //     else if(nums[i]==2){
        //         swap(nums[i],nums[h]);
        //         if(i==h) break;
        //         h--;
        //     }
        //     else{
        //         swap(nums[i],nums[m]);
        //         if(i==m) i++;
        //         m++;
        //     }
        // }
    }
};