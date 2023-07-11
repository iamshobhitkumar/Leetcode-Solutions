class Solution {
public:
    bool check(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(string s, vector<vector<string>>& ans,vector<string>& v, int ind){
        if(ind == s.size()){
             ans.push_back(v);
             return;
        }
        for(int i = ind; i<s.size();i++){
            if(check(s,ind,i)){
                v.push_back(s.substr(ind,i-ind+1));
                solve(s,ans,v,i+1);
                v.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(s,ans,v,0);
        return ans;
    }
};