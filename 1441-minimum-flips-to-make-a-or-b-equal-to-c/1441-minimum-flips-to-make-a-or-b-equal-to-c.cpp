class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        int ma = max(a,max(b,c));
        while(ma){
            bool flag = a%2 | b%2;
            bool flag2 = c%2;
            cout<<flag<<" "<<flag2<<endl;
            if(flag != flag2){
                if(c%2){
                    ans++;
                }
                else{
                    if(a%2 && b%2)
                        ans+=2;
                    else
                        ans++;
                }
                cout<<a%2<<" "<<b%2<<" "<<c%2<<" "<<ans<<endl;
            }
            a/=2;
            b/=2;
            c/=2;
            ma/=2;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        return ans;
    }
};