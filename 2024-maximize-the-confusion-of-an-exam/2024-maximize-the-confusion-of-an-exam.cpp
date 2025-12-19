class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        long long left=0;
        int tcnt=0;
        int fcnt=0;
        long long res=INT_MIN;
        for(int right=0;right<s.size();right++){
            if(s[right]=='F')fcnt++;
            while(fcnt>k){
                if(s[left]=='F'){
                    fcnt--;
                }
                left++;
            }
            res=max(res,right-left+1);
        }
        left=0;
        long long res2=INT_MIN;
        for(int right=0;right<s.size();right++){
            if(s[right]=='T')tcnt++;
            while(tcnt>k){
                if(s[left]=='T'){
                    tcnt--;
                }
                left++;
            }
            res2=max(res2,right-left+1);
        }

        return max(res,res2);
    }
};