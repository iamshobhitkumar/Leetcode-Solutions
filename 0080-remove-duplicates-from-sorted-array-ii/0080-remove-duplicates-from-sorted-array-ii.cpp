class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for(auto it = nums.begin()+1;it!=nums.end();){
            if(*it == *(it-1)){
                count++;
                if(count>2){
                    nums.erase(it);
                    count--;
                }
                else{
                    it++;
                }
            }
            else{
                count = 1;
                it++;
            }
        }
        return nums.size();
    }
};