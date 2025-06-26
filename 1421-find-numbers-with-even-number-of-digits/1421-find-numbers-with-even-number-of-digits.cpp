class Solution {
public:
    int findNumbers(vector<int>& nums) {
        vector<string>str;
        int count=0;
        for(auto num:nums){
            string temp=to_string(num);
            str.push_back(temp);
        }
        for(auto num:str){
            if(num.size()%2==0){
                count++;
            }
        }
        return count;
    }
};