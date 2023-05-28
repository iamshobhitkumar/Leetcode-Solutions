class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        int n = s.size();
        int m = t.size();
        if(n!=m)
            return false;
        for(int i=0;i<n;i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(auto it = m1.begin();it!= m1.end();it++){
            if(m2.find(it->first) == m2.end())
                return false;
            if(m2[it->first]!=m1[it->first])
                return false;
        }
        return true;
    }
};