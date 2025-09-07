class Solution {
public:
    int minOperations(string s) {
       char minchar='z'+1;
       for(auto ch:s){
            if(ch!='a'){
                minchar=min(minchar,ch);
            }
       }
       if(minchar=='z'+1){
        return 0;
       }else{
        return 26-(minchar-'a');
       }
       return 0;
    }
};