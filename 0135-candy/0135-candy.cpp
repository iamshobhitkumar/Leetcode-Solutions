class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;
        vector<int> v(n,1);
            for(int i=0;i<n-1;i++){
                if(ratings[i] > ratings[i+1]){
                    if(v[i] > v[i+1]) continue;
                    candies += v[i+1]-v[i]+1;
                    v[i] = v[i+1]+1;
                }
                else if(ratings[i] < ratings[i+1]){
                    if(v[i+1] > v[i]) continue;
                    candies += v[i]-v[i+1] +1;
                    v[i+1] = v[i]+1;
                }
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i] > ratings[i-1]){
                    if(v[i] > v[i-1]) continue;
                    candies += v[i-1]-v[i]+1;
                    v[i] = v[i-1]+1;
                }
                else if(ratings[i] < ratings[i-1]){
                    if(v[i-1] > v[i]) continue;
                    candies += v[i]-v[i-1] +1;
                    v[i-1] = v[i]+1;
                }
        }
        return candies;
    }
};