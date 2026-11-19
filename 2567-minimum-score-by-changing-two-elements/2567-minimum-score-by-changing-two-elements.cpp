class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
       
        sort(nums.begin(),nums.end());
        int case_1=nums[n-1]-nums[2];
        int case_2=nums[n-3]-nums[0];
        int case_3=nums[n-2]-nums[1];
        return min({case_1,case_2,case_3});

    }
};