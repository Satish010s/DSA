class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int totalXOR=0;
        bool hasnonzero=false;
        for(int i=0;i<nums.size();i++){
            totalXOR ^= nums[i];
            if(nums[i] != 0){
                hasnonzero=true;
            }
        }
        if(totalXOR != 0) return nums.size();
        else if(hasnonzero) return nums.size()-1;
        else return 0;
    }
};