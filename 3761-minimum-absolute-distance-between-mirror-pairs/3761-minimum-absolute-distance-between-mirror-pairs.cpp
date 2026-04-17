class Solution {
public:
    int rev(int n){
        int res =0;
        while(n){
            res = res * 10 + (n % 10);
            n /= 10;
        }
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> map;
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            int revcurr = rev(curr);

            if(map.count(curr)){
                res = min(res, abs(i - map[curr]));
            }

            map[revcurr] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};