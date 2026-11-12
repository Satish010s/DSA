class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int   ans=1;
        int  leftCount=1;
        int rightCount=1;
        int i=1,j=n-2;
        while(i<n  && j>=0){
            if(nums[i] <=nums[i-1]  ) leftCount=1;
            else leftCount++;

            if(nums[j]<=nums[j+1])  rightCount=1;
            else rightCount++;
            ans=max({ans,leftCount,rightCount});
            i++,j--;
        }
        return ans;
    }
};