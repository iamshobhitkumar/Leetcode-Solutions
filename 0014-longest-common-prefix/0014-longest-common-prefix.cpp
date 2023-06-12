class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";
        int n = strs.size();
        if(n==0) return "";
        if(n==1) return strs[0];
        int j = 0;
        while(true){
            for(int i=0;i<n-1;i++){
                if(j>= strs[i].size() || j>=strs[i+1].size())
                  return ans;
                if(strs[i][j] != strs[i+1][j])
                    return ans;
            }
            ans += strs[0][j];
            j++;
        }
        return ans;   
    }
};