class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int zeroIdx=0;
        for( int i=0;i<n;i++){
            if(nums[i]==0){
                zeroIdx=i;
                break;
            }
        }
        bool isIncreasing=true;
        bool isDecreasing=true;

        for( int i=0;i<n;i++){
            //checking increasing
            if(nums[(zeroIdx+i)%n]!=i){
                isIncreasing=false;
            }
             if(nums[(zeroIdx-i+n)%n]!=i){
                isDecreasing=false;
            }
        }
        if(!isIncreasing && !isDecreasing) return -1;
        int ans=1e9;
        if(isIncreasing){
            int shift=zeroIdx;
            int revShiftRev=1+(n-zeroIdx)+1;
            ans=min({ans,shift,revShiftRev});
        }
        if(isDecreasing){
            int shiftRev=(zeroIdx+1)+1;
            int revShift=1+(n-zeroIdx-1);
            ans=min({ans,shiftRev,revShift});
        }
        return ans;
    }
};