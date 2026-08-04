class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int m=*max_element(nums.begin(),nums.end());
        int n=*min_element(nums.begin(),nums.end());

        for(int i=n;i<=m;i++){
            int flag=0;
           for(int j=0;j<nums.size();j++){
            if(nums[j]==i){
                flag=1;
                break;
            }
           }
            if(flag==0) ans.push_back(i);
        }
        return ans ;
    }
};