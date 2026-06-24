class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int res=0;
        int i=0;
        while(true){
            if(i==costs.size()){
                break;
            }
            if(costs[i]<=coins){
                res++;
                coins=coins-costs[i];
                i++;
            }else{
                break;
            }
        }
        return res;
    }
};