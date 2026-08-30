class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int max_p=0;
        int min_q=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                max_p=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                min_q=i;
            }
        }
        int left = min(min_q, max_p);
        int right = max(min_q, max_p);
        
        int path1 = right + 1;                  
        int path2 = n - left;                  
        int path3 = (left + 1) + (n - right);   
        
        return min({path1, path2, path3});

    }
};