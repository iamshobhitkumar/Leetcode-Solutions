class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_map<string, char> m1;
        int i=0;
        int index = 0;
        while(i<pattern.size() && index<s.size()){
            string sub = "";
            while(s[index]!= ' ' && index<s.size()){
                sub+= s[index];
                cout<<"Interted "<<s[index]<<endl;
                index++;
            }
            cout<<"Exited while loop"<<endl;
            index++;
            if(m.find(pattern[i]) == m.end() && m1.find(sub) == m1.end() && sub.size()>0){
                m.insert(make_pair(pattern[i],sub));
                m1[sub] = pattern[i];
            }
            else{
                if(m[pattern[i]]!=sub || m1[sub]!=pattern[i])
                    return false;
            }
            i++;
        }
        if(index<s.size() || i<pattern.size())
            return false;
        return true;
    }
};