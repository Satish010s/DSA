class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans;
        int depth=0;
        int flag=0;
        for(int i=0;i<n;i++){
            if(i>0 && seq[i]==')' && seq[i-1]=='(') {
                ans.push_back(flag);
               
            }
            else if(i>0 && seq[i]=='(' && seq[i-1]==')'){
                ans.push_back(flag);
            }
            else if(i>0 && seq[i]=='(' && seq[i-1]=='(' || seq[i]==')' && seq[i-1]==')'){
                if(flag==0) flag=1;
                else flag=0;
                ans.push_back(flag);
            }
            else{
                ans.push_back(flag);
               
            }
        }
        
        return ans;
    }
};