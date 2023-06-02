class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(true){
            if(n==1)
                return true;
            if(s.find(n) == s.end())
                s.insert(n);
            else
                return false;
            int temp = 0;
            while(n){
                temp += (n%10)*(n%10);
                n/=10;
            }
            n = temp;
        }
    }
};