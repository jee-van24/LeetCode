class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;
        for(int i=1;i<=9;i++){
            int num=i;
            if(num>=low&&num<=high){
                res.push_back(num);
            }
            int next=i+1;
            while(num<=high){
                num*=10;
                if(next!=10){
                    num+=next;
                    next+=1;
                }else{
                    break;
                }
                
                if(num>=low&&num<=high){
                    res.push_back(num);
                }else if(num>high){
                    break;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;

    }
};