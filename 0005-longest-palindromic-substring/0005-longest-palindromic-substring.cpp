class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int left=0;
        int right=0;
        while(left<s.size()){
            right=left;
            while(right<s.size()){
                if(s[left]==s[right]){
                    int l=left;
                    int r=right;
                    bool palin=true;
                    while(l<r){
                        if(s[l]!=s[r]){
                            palin=false;
                            break;
                        }else{
                            l++;
                            r--;
                        }
                    }
                    if(palin==true){
                        string temp=s.substr(left,right-left+1);
                        if(temp.size()>res.size()){
                            res=temp;
                            temp.clear();
                        }
                    }

                }
                    right++;
            }
            left++;
        }
        return res;
    }

};