class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        string res="";
        int i=0;
        while(i<n){
            if(s[i]==')'){
                string m="";

                while(!st.empty() && st.top()!='('){
                    m+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                st.pop();
                }

                for(char c:m){
                    st.push(c);
                }
                i++;
                continue;
            }
            st.push(s[i]);
            i++;
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};