class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        unordered_map<string, int> map{
            {"++X", 0}, 
            {"X++", 0},
            {"--X",0},
            {"X--",0}
        };
        for (auto str : operations) {
            map[str]++;
        }
        for (auto &p :map) {
            if(p.first=="X++"||p.first=="++X"){
                res += p.second;
            }else{
                res-=p.second;
            }   
        }
        return res;
    }
};