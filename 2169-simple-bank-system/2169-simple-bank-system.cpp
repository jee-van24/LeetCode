class Bank {
public:
    int n;
    unordered_map<int,long long>map;
    Bank(vector<long long>& balance) {
        n=balance.size();
        for(int i=0;i<balance.size();i++){
            map[i]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
            if(account1-1<n&&account2-1<n){
                if(map[account1-1]>=money){
                    map[account1-1]-=money;
                    map[account2-1]+=money;
                }else{
                    //cant transfer due to lesser balance than given money
                    return false;
                }
            }else{
                return false;
            }
            return true;
    }
    
    bool deposit(int account, long long money) {
        if(map.count(account-1)){//check if the acc exists
            map[account-1]+=money;//deposit successfull
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(map.count(account-1)){
            if(map[account-1]>=money){
                map[account-1]-=money;
                return true; //withdraw successfull
            }else{
                //insufficient money to withdraw
                return false;
            }
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */