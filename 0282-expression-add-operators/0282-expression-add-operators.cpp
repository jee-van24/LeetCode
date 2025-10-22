class Solution {
public:
    void dfs(int idx, long long built_val,long long last_operand,int target,string& curr,string&num,vector<string>&res){
        if(idx==num.size()){
            if(built_val==target){
                res.push_back(curr);
            }
            return;
        }
        string temp="";
        long long currval=0;
        for(int i=idx;i<num.size();i++){
            if(i>idx&&num[idx]=='0'){
                //for leading zeroes case 
                break;
            }
            temp+=num[i];
            currval= stoll(temp);
           
            if(idx==0){
                //no operand to add , add the current number itself 
                curr+=temp;
                dfs(i+1,currval,currval,target,curr,num,res);
                for(int j=0;j<temp.size();j++){
                    curr.pop_back();
                }
            }else{
                //add + - and * 
                curr+="+";
                curr+=temp;
                dfs(i+1,built_val+currval,currval, target,curr,num,res);
                //now backtrack
                for(int j=0;j<temp.size()+1;j++){
                    curr.pop_back();
                }
                curr+="-";
                curr+=temp;
                dfs(i+1, built_val-currval,-currval,target,curr,num,res);
                for(int j=0;j<temp.size()+1;j++){
                    curr.pop_back();
                }
                curr+="*";
                curr+=temp;
                dfs(i+1,built_val-last_operand+last_operand*currval,last_operand*currval,target,curr,num,res);
                for(int j=0;j<temp.size()+1;j++){
                    curr.pop_back();
                }
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string>res;
        string s="";
        dfs(0,0,0,target,s,num,res);
        return res;
    }
};