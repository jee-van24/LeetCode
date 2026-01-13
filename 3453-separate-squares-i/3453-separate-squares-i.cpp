class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double res=0;
        double low=INT_MAX;
        double high=0;
        double total=0;
        for(auto v:squares){
            double currY=v[1]+v[2];
            high=max(high,currY);
            low=min(low,1.0*v[1]);
            total+=1.0*v[2]*v[2];
        }
        for(int i=0;i<70;i++){
            double mid=low+(high-low)/2;
            double below=0;
            res=mid;
            for(const auto & vec:squares){
                double bottom=vec[1],top=vec[1]+vec[2],len=vec[2];
                if(bottom<mid&&mid<top){
                    below+=(mid-bottom)*len;
                }else if(top<=mid){
                    below+=len*len;
                }
            }
            if(below>=total/2){
                high=mid;
            }else{
                low=mid;
            }
        }
        return res;
    }
};