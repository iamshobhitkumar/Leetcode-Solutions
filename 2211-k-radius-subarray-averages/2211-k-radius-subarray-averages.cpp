class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        vector<int> ans(n,0);
        long long sum =0;
        while(i<k && i<n){
            sum += nums[i];
            ans[i++] = -1;
        }
        if(i==n) return ans;
        int l =0,h = i;
        if(i+k>=n){
            ans[i] = -1;
            return ans;
        }
        while(h<=i+k && h<n){
            sum+=nums[h++];
        }
        if(i==n) return ans;
        ans[i++] = sum/(2*k + 1);
        while(h<n){
            sum -= nums[l++];
            sum += nums[h++];
            ans[i++] = sum/(2*k+1);
        }
        while(i<n)
            ans[i++] = -1;
        return ans;
    }
};