class ProductOfNumbers {
public:
    vector<int>vec;
    vector<int>pref;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num);
        if(num==0){
            pref.clear();
            return;
        }
        if(pref.size()==0){
            pref.push_back(num);
        }else{
            pref.push_back(pref.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n=pref.size();
        int res;
        if(n==k){
            //the entire arrays mult , 
            return pref[n-1];
        }
        if(pref.size()<k){
            return 0;//there was a 0 among the last k elements
        }
        res=pref[n-1]/pref[n-1-k];
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */