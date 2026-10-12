class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long  mod=1e9+7;
        int n=nums.size();
        long long  ans=0;
        vector<int>bit_Len(30);
        for(auto &it:nums){
            for(int i=0;i<30;i++){
                if(it&(1<<i)) bit_Len[i]++;
            }
        }

        while(k>0){
            long long  num=0;
            for(int i=0;i<30;i++){
                if(bit_Len[i]>0){
                    num|=1L<<i;
                    bit_Len[i]--;
                }
            }
            ans=(ans+num*num)%mod;
            k--;
        }
    return (int)ans;
    }
};