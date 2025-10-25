class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        bool haszero=false;
        int neg=0;
        int res=0;
        int right,left=0;
        int firstnegidx=-1,lastnegidx=-1;
        for(right=0;right<nums.size();right++){
            if(nums[right]==0){
                haszero=true;
                break;
            }else{
                if(nums[right]<0){
                    if(firstnegidx==-1){
                        firstnegidx=right;
                        lastnegidx=right;
                    }else{
                        lastnegidx=right;
                    }
                    neg++;
                }
            }
        }
        if(!haszero){

            //if no zero, then if total neg count is even => whole array product positive
            if(neg%2==0){
                return nums.size();
            }else{
                //otherwise exclude either prefix till first neg or suffix after last neg
                res=max(res,max(right-firstnegidx-1,lastnegidx-left));
                return res;
            }
        }
        //so basically it has zero now and i have to look for subarrays where zero is not there
        res=0;
        neg=0;
        left=0,right=0;
        firstnegidx=-1,lastnegidx=-1;
        for(right=0;right<nums.size();right++){
            if(nums[right]==0){
                if(neg%2==0){
                    res=max(res,right-left);//can consider that entire subarray cause it has half pos and half neg 
                }else{
                    //exclude one side depending on which gives longer subarray
                    res=max(res,max(right-firstnegidx-1,lastnegidx-left));
                }
                left=right+1;
                neg=0;
                firstnegidx=-1;
                lastnegidx=-1;
                continue;
            }
            if(nums[right]<0){
                neg++;
                if(firstnegidx==-1){
                    firstnegidx=right;
                    lastnegidx=right;
                }else{
                    lastnegidx=right;
                }
            }
        }
        //if after the loop it has something left
        if(neg%2==0){
            res=max(res,right-left);
        }else{
            res=max(res,max(right-firstnegidx-1,lastnegidx-left));
        }
        return res;
    }
};
