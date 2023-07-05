class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0, ans = 0;
        vector<int> v;
        int n = nums.size();
        int i=0;
        while(i<nums.size()){
            if(nums[i] ==0){
                v.push_back(0);
                count++;
                i++;
            }
            else{
                int temp = 0;
                while(i<n && nums[i]!=0){
                    temp++;
                    i++;
                }
                v.push_back(temp);
            }
        }
        if(count == 0) return nums.size()-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                int left = 0, right = 0;
                if(i-1>=0) left += v[i-1];
                if(i+1<v.size()) right += v[i+1];
                ans = max(ans, left+right);
            }
            else ans = max(ans,v[i]);
        }
        return ans;
    }
};