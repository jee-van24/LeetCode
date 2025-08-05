class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0;
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(fruits[i]<=baskets[j]){
                    count++;//satisfied
                    baskets.erase(baskets.begin()+j);//this basket is used
                    break;
                }
            }
        }
        return fruits.size()-count;
    }
};