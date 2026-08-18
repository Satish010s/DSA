class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=-1;
        for(int i=0;i<=n-k;i++){
            unordered_set<int>st;
            for(int j=0;j<k;j++){
                st.insert(nums[i+j]);
            }
            for(int num:st){
                mp[num]++;
            }
        }
        for(auto &it:mp){
            if(it.second==1){
                maxi=max(maxi,it.first);
            }
        }
        return maxi;
    }
};