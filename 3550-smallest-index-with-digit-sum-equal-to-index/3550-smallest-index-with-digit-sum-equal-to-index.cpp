class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int minIdx=INT_MAX;
        int i=0;
        while(i<n){
            int num=nums[i];
            int sum=0;
            while(num!=0){
                sum+=num%10;
                num/=10;
            }
            if(sum==i){
                minIdx=min(minIdx,sum);
            }
            i++;
        }
        return minIdx!=INT_MAX ?minIdx :-1;
    }
};