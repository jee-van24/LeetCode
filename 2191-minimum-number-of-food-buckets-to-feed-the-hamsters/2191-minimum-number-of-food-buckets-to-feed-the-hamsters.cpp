class Solution {
public:
    int minimumBuckets(string hamsters) {
        int count=0;
        int n=hamsters.size();
        for(int i=0;i<hamsters.size();i++){
            if(hamsters[i]=='H'){
                if(i>0&&hamsters[i-1]=='1'){
                    continue;
                }
                else if(i+1<n&&hamsters[i+1]=='.'){
                    count++;
                    hamsters[i+1]='1';
                }else if(i>0&&hamsters[i-1]=='.'){
                    hamsters[i-1]='1';
                    count++;
                }else{
                    return -1;
                }
            }
            
        }
        
        return count;
    }
};