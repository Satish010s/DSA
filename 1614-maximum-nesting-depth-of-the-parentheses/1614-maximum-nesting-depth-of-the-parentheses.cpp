class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        long long  count=0;
        long long  maxi=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                count++;
                maxi=max(maxi,count);
            }
            else if(s[i]==')'){
                 count--;
                maxi=max(maxi,count);
            }
              i++;
        }
        return maxi;
    }
};