class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>map;
        if(nums.size()%k!=0)return false;
        for(auto n:nums)map[n]++;
        while(true){
            if(map.empty())break;
            int prev=map.begin()->first;
            vector<int>temp;
            temp.push_back(prev);
            for(auto &p:map){
                if(temp.size()==k)break;
                if(p.first==prev+1){
                    temp.push_back(p.first);
                    prev+=1;
                }
            }
            if(temp.size()!=k)return false;
            for(int i=0;i<temp.size();i++){
                map[temp[i]]--;
                if(map[temp[i]]==0){
                    map.erase(temp[i]);
                }
            }
        }
        return true;
    }
};