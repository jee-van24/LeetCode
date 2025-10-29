class Solution {
public:
    int smallestNumber(int n) {
        string binary=bitset<32>(n).to_string();
        int len=binary.size();
        string check="";
        for(int i=0;i<32;i++){
            check.push_back('1');
            int decimal = stoi(check, nullptr, 2);
            if(decimal>=n){
                return decimal;
            }
        }
        return 0;
    }
};