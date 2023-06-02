class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        queue<int>q;
        for(auto i:nums){
            q.push(i);
        }
        int temp = n-k;
        while(temp--){
            int top = q.front();
            q.pop();
            q.push(top);
        }
        for(int i=0;i<n;i++){
            nums[i] = q.front();
            q.pop();
        }
    }
};