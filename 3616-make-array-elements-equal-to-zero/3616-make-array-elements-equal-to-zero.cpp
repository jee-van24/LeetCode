class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (auto n : sum) {
            cout << n << " ";
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i>0&&nums[i] == 0) {
                int right=sum[n-1]-sum[i];
                int left=sum[i-1];
                if(left==right){
                    res += 2;
                }  
                if(right+1==left){
                    res+=1;
                }
                if(left+1==right){
                    res+=1;
                }
            }else if(i==0&&nums[0]==0){
                if(sum[n-1]==0){
                    res+=2;
                }else if(sum[n-1]==1){
                    res+=1;
                }
            }
        }
        cout<<res;

        return res;
    }
};