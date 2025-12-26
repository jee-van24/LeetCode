class Solution {
public:
    int bestClosingTime(string customers) {
        int res=INT_MAX;
        int idx=-1;
        int n=customers.size();
        vector<int>ycnt(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')cnt++;
            ycnt[i]=cnt;
        }
        vector<int>ncnt(n,0);
        cnt=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='N')cnt++;
            ncnt[i]=cnt;
        }

        for(auto n:ycnt){
            cout<<n<<" ";
        }
        cout<<endl;
        for(int j=0;j<n;j++){
            int ns=(j==0)?0:ncnt[j-1];
            int ys=ycnt[n-1]-(j>0?ycnt[j-1]:0);
            int pen=ns+ys;
            if(pen<res){
                res=pen;
                idx=j;
            }
        }
        int pen_n=ncnt[n-1];
        if(pen_n<res){
            idx=n;
        }

        return idx;   
    }
};