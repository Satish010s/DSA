class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int num=x;
        int totalSum =0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        int target=totalSum-x;
        if(target==0) return n;
        if(target<0) return -1;
        int maxLen=-1;
        int i=0,j=0;
        int currSum=0;
        while(j<n){
            currSum+=nums[j];
          while(currSum>target && i<=j){
               currSum-=nums[i];
                i++;
            }
            if(currSum==target){
              maxLen=max(maxLen,j-i+1);
            }
            j++;
        }
        if(maxLen!=-1)  return n-maxLen;
        return -1;
    }
};