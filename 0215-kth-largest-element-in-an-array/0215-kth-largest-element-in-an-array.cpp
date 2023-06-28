class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto it: nums) q.push(it);
        while(--k) q.pop();
        return q.top();
    }
};