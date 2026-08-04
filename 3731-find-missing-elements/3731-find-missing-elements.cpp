class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int m=*max_element(nums.begin(),nums.end());
        int n=*min_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>=2){
                int num=nums[i-1]+1;
                while(num!=nums[i]){
                    ans.push_back(num);
                    num++;
                }
            }
        }
       
        return ans ;
    }
};