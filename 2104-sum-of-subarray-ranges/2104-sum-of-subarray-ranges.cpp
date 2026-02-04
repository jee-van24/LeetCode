class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<vector<int>>s;
        int n=nums.size();
        vector<int>nextgreater(n,n),nextsmaller(n,n),prevgreater(n,-1),prevsmaller(n,-1);
        for(int i=0;i<nums.size();i++){
            while(!s.empty()&&s.top()[1]<=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                prevgreater[i]=s.top()[0];
            }else{
                prevgreater[i]=-1;
            }
            s.push({i,nums[i]});
        }
        while(!s.empty()){
            s.pop();
        }
        cout<<"prevgreater : ";
        for(auto n:prevgreater){
            cout<<n<<" ";
        }
        cout<<endl;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top()[1]<nums[i]){
                s.pop();
            }
            if(!s.empty()){
                nextgreater[i]=s.top()[0];
            }else{
                nextgreater[i]=n;
            }
            s.push({i,nums[i]});
        }
        cout<<"nextgreater : ";
        for(auto n:nextgreater){
            cout<<n<<" ";
        }
        cout<<endl;
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top()[1]>=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                prevsmaller[i]=s.top()[0];
            }else{
                prevsmaller[i]=-1;
            }
            s.push({i,nums[i]});
        }
        cout<<"prevsmaller : ";
        for(auto n:prevsmaller){
            cout<<n<<" ";
        }
        cout<<endl;
        while(!s.empty()){
            s.pop();
        }
        cout<<"nextsmaller : ";
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top()[1]>nums[i]){
                s.pop();
            }
            if(!s.empty()){
                nextsmaller[i]=s.top()[0];
            }else{
                nextsmaller[i]=n;
            }
            s.push({i,nums[i]});
        }
        for(auto n:nextsmaller){
            cout<<n<<" ";
        }
        long long res=0;
        for(int i=0;i<n;i++){
            int lmax=i-prevgreater[i];
            int rmax=nextgreater[i]-i;
            int lmin=i-prevsmaller[i];
            int rmin=nextsmaller[i]-i;
            res += 1LL * nums[i] * lmax * rmax;
            res -= 1LL * nums[i] * lmin * rmin;

        }
        return res;
    }
};