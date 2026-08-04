class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int m=*max_element(nums.begin(),nums.end());
        int n=*min_element(nums.begin(),nums.end());
        for(int num : nums){
            mp[num]=1;
        }
        for(int i=n;i<=m;i++){
            if(mp[i]==0){
                ans.push_back(i);
            }
        }
        return ans ;
    }
};