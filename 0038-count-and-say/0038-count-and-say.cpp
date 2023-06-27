class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev = "11";
        string ans = "";
        for(int i=2;i<n;i++){
            int count = 1;
            for(int j=0;j<prev.size()-1;j++){
                if(prev[j] == prev[j+1])
                    count++;
                else{
                    ans += to_string(count);
                    ans += prev[j];
                    count = 1;
                }
            }
            ans += to_string(count);
            ans+= prev[prev.size()-1];
            prev = ans;
            ans ="";
        }
        return prev;
    }
};