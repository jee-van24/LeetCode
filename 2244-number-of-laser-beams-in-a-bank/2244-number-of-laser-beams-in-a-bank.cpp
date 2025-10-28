class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=-1;
        int res=0;
        for(auto row:bank){
            int curr=0;
            for(auto device:row){
                if(device=='1'){
                    curr++;
                }
            }
            if(curr!=0){
                if(prev!=-1){
                    res+=prev*curr;
                }
                prev=curr;
            }
        }

        cout<<res;
        return res;
    }
};