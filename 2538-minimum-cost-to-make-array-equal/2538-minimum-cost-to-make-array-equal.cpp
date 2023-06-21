class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = 1, r = 1000000, res = 0, res1 = 0;
        while (l < r) {
            int m = (l + r) / 2;
            res = res1 = 0;
            for (int i = 0; i < nums.size(); ++i) {
                res += (long long)cost[i] * abs(nums[i] - m);
                res1 += (long long)cost[i] * abs(nums[i] - (m + 1));
            }
            if (res < res1)
                r = m;
            else
                l = m + 1;
        }
        return min(res, res1); 
    }
};