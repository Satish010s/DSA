class Solution {

private:
        bool isValid(string &p){
            int count=0;
            for(int i=0;i<p.size();i++){
                if(p[i]=='(') count++;
                else if(p[i]==')')count--;
                if(count<0) return false;
            }
            return count==0;
        }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        if (s.empty()) return {""};
        vector<string>result;
        queue<string>q;
        unordered_set<string>visited;
        q.push(s);
        visited.insert(s);
        bool found=false;
        while(!q.empty()){
            int level_size=q.size();
            for(int i=0;i<level_size;i++){
                string curr=q.front();
                q.pop();
                if(isValid(curr)){
                    result.push_back(curr);
                    found=true;    
                }
                if(found==true) continue;

                //generate all children with that curr string 
                for(int j=0;j<curr.size();j++){
                    if(curr[j]!='(' && curr[j]!=')') continue;

                    string new_str=curr.substr(0,j)+curr.substr(j+1);

                    if(visited.find(new_str)==visited.end()){
                        visited.insert(new_str);
                        q.push(new_str);
                    }
                }
            }
            if(found==true) break;
        }
        return result;
    }
};