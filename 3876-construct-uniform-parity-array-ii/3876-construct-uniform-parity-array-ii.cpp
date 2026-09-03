class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        bool odd=false;
        for(int num:nums1){
            if(num%2!=0) odd=true;
            mini=min(mini,num);
        }
        if(odd && mini % 2==0) return false;
        return true;
    }
};