class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int unmatched_open=0,open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='[') open++;
            else if(open>0 && s[i]==']') open--;

        }
        return (open+1)/2;
    }
};