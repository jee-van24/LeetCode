class ProductOfNumbers {
public:
    vector<int>vec;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        int res=1;
        for(int i=vec.size()-1;k>0;i--){
            if(vec[i]==0)return 0;
            res*=vec[i];
            k--;
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */