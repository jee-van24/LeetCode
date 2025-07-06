class FindSumPairs {
public:
    vector<int>n1,n2;
    unordered_map<int,int>freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
        for(auto num:n2){
            freq[num]++;
        }
    }
    
    void add(int index, int val) {
        int old=n2[index];
        freq[old]--;
        n2[index]+=val;
        freq[n2[index]]++;
    }
    
    int count(int tot) {
        int count=0;
        for(auto num:n1){
            int complement=tot-num;
            if (freq.find(complement) != freq.end()) {
                count += freq[complement];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */