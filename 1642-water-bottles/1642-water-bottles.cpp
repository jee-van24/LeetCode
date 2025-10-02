class Solution {
public:
    int numWaterBottles(int numbottles, int numexchange) {
        int res=numbottles;
        //i can drink minimum of numbottles 
        int empty=numbottles;
        while(empty>=numexchange){
            int newfull=empty/numexchange;
            int modulo=empty%numexchange;
            res+=newfull;
            int newempty=newfull;
            empty=modulo+newempty;
        }
        return res;
    }
};