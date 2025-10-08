class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>res;
        unordered_map<int,int>map;
        sort(potions.begin(),potions.end());
        for(auto currnum:spells){
            if(map[currnum]){
                res.push_back(map[currnum]);
                continue;
            }
            int lb=-1;
            int low=0,high=potions.size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(1ll*currnum*potions[mid]>=success){
                    lb=mid;
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            
            int cnt=(lb==-1)?0:potions.size()-lb;
            res.push_back(cnt);
            map[currnum]=cnt;
            cout<<cnt;
        }
        return res;
    }
};