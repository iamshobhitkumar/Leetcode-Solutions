class Solution {
public:
    long long coloredCells(int n) {
        long long l = 2*n-1;
        long long ans = l;
        l-=2;
        while(l>0){
            ans +=2*l;
            l-=2;
        }
        return ans;
    }
};