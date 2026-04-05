class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0,u=0;
        for(auto ch:moves){
            if(ch=='U'){
                u++;
            }else if(ch=='D'){
                u--;
            }else if(ch=='L'){
                r--;
            }else{
                r++;
            }
        }
        if(u==0&&r==0)return true;
        return false;
    }
};