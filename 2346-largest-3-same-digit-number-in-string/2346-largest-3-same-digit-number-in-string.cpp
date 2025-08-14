class Solution {
public:
    string largestGoodInteger(string num) {
        int n;
        string res="";
        string curr="";
        curr+=num[0];
        for(int i=1;i<num.size();i++){
            if(curr==""){
                curr+=num[i];
                continue;
            }
            if(num[i]==curr.back()){
                curr+=num[i];
            }else{
                curr="";
                curr+=num[i];

            }
            if(curr.size()==3){
                res=max(res,curr);
                curr="";

            }
        }
        return res;     
    }
};