class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        bool isSorted=true;
        char mini=s[0];
        char maxi=s[0];
        for(int i=1;i<n;i++){
            if(s[i-1]>s[i]) isSorted=false;
            mini=min(mini,s[i]);
            maxi=max(maxi,s[i]);
        }
        if(isSorted) return 0;
        if(n==2 && !isSorted) return -1;
        if(s[0]==mini || s[n-1]==maxi) return 1;
        // if(s[0]!=mini && s[n-1]!=maxi) return 2;   this condition  gives wrong answer

        for(int i=1;i<n-1;i++){
            if(s[i]==mini || s[i]==maxi) return 2;
        }
        return 3;
    }
};