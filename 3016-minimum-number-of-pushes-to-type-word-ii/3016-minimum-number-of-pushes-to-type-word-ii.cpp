class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int totalPush=0;

        for(int i=0;i<26;i++){
            if(freq[i]==0) break;
            int mul=(i/8)+1;
            totalPush+=mul*freq[i];
        }
        return totalPush;
    }
};