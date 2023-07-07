class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int countt = 0, countf = 0;
        int l = 0, r = 0, n = answerKey.size();
        int ans = 0;
        int count = 0;
        while(r<n){
            if(answerKey[r]=='T'){
                countt++;
            }
            else{
                count++;
                countt++;
                while(count >k){
                    countt--;
                    if(answerKey[l++] == 'F') count--;
                }
            }
            ans = max(ans,countt);
            r++;
        }
        l = 0, r = 0, count = 0;
        while(r<n){
            if(answerKey[r]=='F'){
                countf++;
            }
            else{
                count++;
                countf++;
                while(count > k){
                    countf--;
                    if(answerKey[l++]=='T') count--;
                }
            }
            ans = max(ans,countf);
            r++;
        }
        return max(ans,max(countt,countf));
    }
};