class Solution {
public:
    int minOperations(string s) {
        bool flag=true;
        int res=0;
        for(auto ch:s){
            if(ch=='a'){
                continue;
            }else{
                flag=false;
                break;
            }
        }
        if(flag){
            return 0;
        }else{
            sort(s.begin(),s.end());
            for(auto ch:s){
                if(ch=='a'){
                    continue;
                }else{
                    res=26-(ch-'a');
                    break;
                }
            }
        }
        return res;
    }
};