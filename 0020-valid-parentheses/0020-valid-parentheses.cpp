class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i: s){
            if(i ==')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(')');
            }
            else if(i =='}'){
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    st.push('}');
            }
            else if(i ==']'){
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    st.push(']');
            }
            else
                st.push(i);
        }
    return st.empty()?true: false;
    }
};