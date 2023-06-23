class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0) return {newInterval};
        vector<vector<int>> v;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(intervals[i][0] > newInterval[0]){
                intervals.insert(intervals.begin()+i,newInterval);
                flag = false;
                break;
            }
        }
        if(flag){
            intervals.push_back(newInterval);
        }
        v.push_back(intervals[0]);
        int i =1;
        while(i<intervals.size()){
            int index = v.size()-1;
                if(v[index][1] < intervals[i][0]){
                    v.push_back(intervals[i]);
                }
                else{
                    if(v[index][1] < intervals[i][1]){
                        v[index][1] = intervals[i][1];
                    }
                }
            i++;
        }
        return v;
    }
};