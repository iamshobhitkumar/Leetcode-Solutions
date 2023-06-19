class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.size()){
                char t = st.top();
                if(t =='A'){
                    if(s[i]=='B'){
                        st.pop();
                        continue;
                    }
                    else st.push(s[i]);
                }
                else if(t =='C'){
                    if(s[i]=='D'){
                        st.pop();
                        continue;
                    }
                    else st.push(s[i]);
                }
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        return st.size();
    }
};