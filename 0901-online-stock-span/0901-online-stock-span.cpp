class StockSpanner {
public:
    stack<vector<int>>s;
    int idx;
    StockSpanner() {
         idx=-1;
    }
    int next(int price) {
        idx+=1;
        while(!s.empty()&&s.top()[0]<=price){
            s.pop();
        }
        int res=0;
        if(!s.empty()){
            res=idx-s.top()[1];
        }else{
            res=idx+1;
        }
        s.push({price,idx});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */