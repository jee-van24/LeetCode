class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        char prev = colors[0];
        int prevtime=neededTime[0];
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == prev) {
                res+=min(neededTime[i],prevtime);
                if(neededTime[i]>prevtime){
                    prev=colors[i];
                    prevtime=neededTime[i];
                }
                continue;
            }else{
                prev=colors[i];
                prevtime=neededTime[i];
            }
        }
        return res;
    }
};