class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> evenprefix(n, 0);
        vector<int> oddprefix(n, 0);

        // build evenprefix separately
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                evenprefix[i]=nums[i];
            } else if (i % 2 == 0) {
                evenprefix[i] = evenprefix[i - 2] + nums[i];
            } else {
                evenprefix[i] = evenprefix[i - 1];
            }
        }

        // build oddprefix separately
        for (int i = 1; i < n; i++) {
            if (i == 1) {
                oddprefix[i] =nums[i];
            } else if (i % 2 == 1) {
                oddprefix[i] = oddprefix[i - 2] + nums[i];
            } else {
                oddprefix[i] = oddprefix[i - 1];
            }
        }
        for(auto n:evenprefix){
            cout<<n<<" ";
        }
        cout<<endl;
        for(int n:oddprefix){
            cout<<n<<" ";
        }
        int res=0;
        for(int i=0;i<n;i++){
            int currevensum=(i==0)?0:evenprefix[i-1];
            int curroddsum=(i==0)?0:oddprefix[i-1];
            int evenafter=oddprefix[n-1]-oddprefix[i];
            int oddafter=evenprefix[n-1]-evenprefix[i];
            int neweven=currevensum+evenafter;
            int newodd=curroddsum+oddafter;
            if(newodd==neweven){
                res++;
            }
        }
        return res;
    }
};