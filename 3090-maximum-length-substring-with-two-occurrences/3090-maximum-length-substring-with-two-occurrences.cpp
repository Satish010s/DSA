class Solution {
public:
    int maximumLengthSubstring(string s) {
          int n=s.size();
        int maxi=INT_MIN;
        unordered_map<int,int>mp;
        int i=0,j=0;
        int len=0;
        int flag=0;
        while(i<n && j<n){
            mp[s[j]]++;
            len++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                len--;
                maxi=max(maxi,len);
                flag=1;
                i++;
            }
            maxi=max(maxi,len);
            j++;
        }
        if(flag==0) return n;
        return maxi;
    }
};