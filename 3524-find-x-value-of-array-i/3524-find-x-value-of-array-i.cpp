class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>result(k,0);
        vector<long long>dp(k,0);
        for(int num:nums){
             vector<long long>new_dp(k,0);
            int curr_rem=((num%k)+k)%k;
            new_dp[curr_rem]+=1;
            for(int rem=0;rem<k;rem++){
                if(dp[rem]>0){
                    int new_rem=(rem*curr_rem)%k;
                    new_dp[new_rem]+=dp[rem];
                }
            }
            for (int r = 0; r < k; ++r) {
                result[r] += new_dp[r];
            }
               dp = std::move(new_dp);
        }
        return result;
    }
};