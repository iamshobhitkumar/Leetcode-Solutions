class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s == goal)
            return (set<char>(s.begin(), s.end()).size() < s.size());
        
        int n = s.length();
        int l = 0, r = n-1;
        
        while(l < n && s[l] == goal[l])
            l++;
        while(r >= 0 && s[r] == goal[r])
            r--;
        if(l < r)
            swap(s[l], s[r]);
        
        return s == goal;  
    }
};