class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int longest = 0;
        for(auto& num : s) {
            int cur_longest = 1;
            for(int j = 1; s.count(num - j); j++) s.erase(num - j), cur_longest++;
            for(int j = 1; s.count(num + j); j++) s.erase(num + j), cur_longest++;
            longest = max(longest, cur_longest);
        }
        return longest;
    }
};