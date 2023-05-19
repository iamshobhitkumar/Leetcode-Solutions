class Solution {
public:
    int st = 0, ed = 0;
    void extend(string s, int i , int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        if(ed-st < j-i-2){
            st = i+1;
            ed = j-1;
        }
    }
    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            extend(s,i,i);
            extend(s,i,i+1);
        }
        string ans = "";
        while(st<=ed){
            ans += s[st++];
        }
        return ans;
    }
};