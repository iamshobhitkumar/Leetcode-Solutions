class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> v;
        for(int i=0;i<weights.size()-1;i++){
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.begin(),v.end());
        long long mini = 0, maxi = 0;
        for(int i=0;i<k-1;i++){
            mini += v[i];
            maxi += v[weights.size()-2-i];
        }
        return maxi-mini;
    }
};