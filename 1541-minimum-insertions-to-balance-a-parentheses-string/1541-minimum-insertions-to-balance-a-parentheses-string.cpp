class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int open=0;
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='(') open++;
            else if(open>0 && s[i]==')'){
                if(i+1<n && s[i+1]==')'){
                    open--;
                    i++;
                }
                else{
                    open--;
                    ans++;
                }
            }
            else{
                if(i+1<n && s[i+1]==')'){
                    ans++;
                    i++;
                }
                else  ans+=2;
            }
            i++;
        }
       return  ans+open*2;
    }
};