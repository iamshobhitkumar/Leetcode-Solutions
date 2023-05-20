class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, h = numbers.size()-1;
        while(l<h){
            if(numbers[h]+numbers[l] > target)
                h--;
            else if(numbers[h]+numbers[l] < target)
                l++;
            else{
                return {l+1,h+1};
            }
        }
        return {-1,-1};
    }
};