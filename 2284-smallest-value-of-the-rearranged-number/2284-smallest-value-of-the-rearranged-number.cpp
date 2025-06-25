class Solution {
public:
    long long smallestNumber(long long num) {
        if(num<0){
            num=fabs(num);
            string str=to_string(num);
            sort(str.begin(),str.end(),greater<char>());
            num=stoll(str);
            num/=-1;
            return num;
        }else{
            string str=to_string(num);
            sort(str.begin(),str.end());
            if(str[0]=='0'){
                int i=0;
                while(i<str.size()){//keep going till you find the first non zero number 
                    if(str[i]!='0'){
                       swap(str[0],str[i]);
                       break;//swapping done hopefully the smallest 

                    }
                    i++;
                }
            }
                num=stoll(str);//convert it back to long long
            
        }
        return num;
    }
};