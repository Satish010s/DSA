class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int moves=0;
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];
        for(int it:nums){
            if(it!=median){
                moves+=abs(it-median);
            }
        }
        return moves;
    }
};