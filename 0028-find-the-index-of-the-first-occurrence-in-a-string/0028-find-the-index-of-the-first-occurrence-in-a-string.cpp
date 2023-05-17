class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j=0;
        int index = -1;
        bool flag = false;
        while(i<haystack.size() && j<needle.size()){
            if(needle[j]==haystack[i]){
                if(!flag)
                    index = i; 
                i++;
                j++;
                flag = true;
            }
            else{
                j=0;
                if(flag)
                    i = index+1;
                else
                    i++;
                flag = false;
            }
        }
        return j==needle.size()?index:-1;
    }
};