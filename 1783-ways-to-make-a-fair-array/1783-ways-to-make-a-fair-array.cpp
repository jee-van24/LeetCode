class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        unordered_map<int,int>evensum,oddsum;
        for(int i=0;i<n;i++){
            if(i==0){
                evensum[i]=nums[i];
                oddsum[i]=0;
            }else{
                if(i%2==0){
                    evensum[i]=evensum[i-2]+nums[i];
                    oddsum[i]=oddsum[i-1];
                }else{
                    oddsum[i]=oddsum[i-2]+nums[i];
                    evensum[i]=evensum[i-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            int curreven=(i==0)?0:evensum[i-1];
            int oddafter=oddsum[n-1]-oddsum[i];
            int currodd=(i==0)?0:oddsum[i-1];
            int evenafter=evensum[n-1]-evensum[i];
            if(curreven+oddafter==currodd+evenafter){
                res++;
            }
        }
        return res;
    }
};