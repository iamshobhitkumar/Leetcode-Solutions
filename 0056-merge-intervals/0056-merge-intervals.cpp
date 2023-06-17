class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=0, j = 1;
        while(j<intervals.size()){
            if(intervals[i][0] >= intervals[j][0]){
                intervals[i][0] = intervals[j][0];
                if(intervals[i][1] < intervals[j][1]){
                    intervals[i][1] = intervals[j][1];
                }
                intervals.erase(intervals.begin()+j);
            }
            else if(intervals[i][1] >= intervals[j][0]){
                if(intervals[i][1] < intervals[j][1]){
                    intervals[i][1] = intervals[j][1];
                }
                intervals.erase(intervals.begin()+j);
            }
            else{
                i++;
                j++;
            }
        }
        return intervals;
    }
};