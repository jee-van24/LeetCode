class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        cout<<(1<<n);
        unordered_set<string>set(nums.begin(),nums.end());
        for(int i=0;i<(1<<n);i++){
            bitset<32>b(i);
            string s=b.to_string();
            if(s.size()>n){
                int diff=s.size()-n;
                s=s.substr(diff);
            }
            if(set.find(s)==set.end()){
                return s;
            }
        }
        return "";
    }
};