class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ans=INT_MAX;
        int j=0;
        while(j<=n-l){
            int i=j;
            int sum=0;
            while(i<j+l){
                sum+=nums[i];
                i++;
            }
            if(sum>0){
                ans=min(ans,sum);
            }
            while(i<j+r && i<n){
                sum+=nums[i];
                if(sum>0){
                ans=min(ans,sum);
                }
                i++;
            }
            j++;
        }
        return ans==INT_MAX ? -1 :ans;
    }
};