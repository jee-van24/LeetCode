class Solution {
public:
    int ispossible(int n){
        int s=1+n;
        int cnt=2;
        cout<<"for 21 "<<endl;
        for(int i=2;i*i<=n;i++){
            if(cnt>4)return 0;
            if(n%i==0){
                cout<<i<<" ";
                cnt++;
                s+=i;
                if(i!=n/i){
                    cnt++;
                    s+=n/i;
                    cout<<n/i<<" "; 
                }
            }
        }
        if(cnt==4)return s;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>map;
        for(auto n:nums){
            if(map.count(n)){
                res+=map[n];
            }else{
                int s=ispossible(n);
                if(s!=0){
                    res+=s;
                    map[n]=s;//for further use 
                }
            }
        }
        return res;
    }
};