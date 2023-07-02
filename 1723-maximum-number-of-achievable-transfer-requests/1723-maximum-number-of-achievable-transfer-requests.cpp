class Solution {
public:
    int solve(vector<vector<int>>& requests, vector<int>& bal, int i, int n){
        if(i==requests.size()){
            return count(bal.begin(), bal.begin()+n, 0) == n? 0:INT_MIN;
        }
        --bal[requests[i][0]];
        ++bal[requests[i][1]];
        int take = 1 + solve(requests, bal, i+1,n);
        ++bal[requests[i][0]];
        --bal[requests[i][1]];
        return max(take, solve(requests, bal, i+1,n));
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> bal(21,0);
        return solve(requests, bal, 0,n);
    }
};