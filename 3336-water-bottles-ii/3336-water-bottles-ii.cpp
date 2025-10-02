class Solution {
public:
    int maxBottlesDrunk(int numbottles, int numexchange) {
        // i will drink all the bottles first so 
        int res=numbottles;
        int emptybott=numbottles;
        while(emptybott>=numexchange){
            // i will exchange numexchange number of bottles with one full bottle 
            res++;
            emptybott-=numexchange;
            numexchange++;
            emptybott++;
        }
        return res;
    }
};