class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int count = 1;
        vector<vector<int>> v;
        v.push_back({1});
        if(numRows==1)
            return v;
        while(count<numRows){
            v.push_back({v[count-1][0]});
            int i=0, j = 1;
            while(j<v[count-1].size()){
                v[count].push_back(v[count-1][i++]+v[count-1][j++]);
            }
            v[count].push_back(v[count-1][v[count-1].size()-1]);
            count++;
        }
        return v;
    }
};