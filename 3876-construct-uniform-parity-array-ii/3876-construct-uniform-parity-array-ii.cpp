class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        bool odd=false;
        for(int num:nums1){
            if(num%2!=0) odd=true;
            maxi=max(maxi,num);
            mini=min(mini,num);
        }
        if(odd && mini % 2==0) return false;
        return true;
    }
};