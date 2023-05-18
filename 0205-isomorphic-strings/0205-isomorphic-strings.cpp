class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_set<char> m1;
        unordered_set<char> m2;
        int count1=0,count2=0;
        for(auto i:s){
            if(m1.find(i)==m1.end()){
                count1++;
                m1.insert(i);
            }
        }
        for(auto i: t){
            if(m2.find(i)==m2.end()){
                count2++;
                m2.insert(i);
            }
        }
        if(count1!=count2)
            return false;
        unordered_map<char,char> m;
        int i=0, j=0;
        if(s.size()!=t.size())
            return false;
        while(i<s.size()){
            if(m.find(s[i])==m.end())
                m[s[i]] = t[j];
            else{
                if(m[s[i]]!=t[j])
                    return false;
            }
            i++;
            j++;
        }
        return true;
    }
};