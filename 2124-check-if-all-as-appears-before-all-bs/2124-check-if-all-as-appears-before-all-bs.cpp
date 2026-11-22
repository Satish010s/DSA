class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int idx_b=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                idx_b=i;
                break;
            }
        }
        if(idx_b!=-1){
        for(int i=idx_b+1;i<n;i++){
            if(s[i]=='a') return false;
        }
        }
        return true;
    }
    
};