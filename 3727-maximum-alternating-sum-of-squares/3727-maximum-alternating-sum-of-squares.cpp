class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<long long>seq;
        for(int num:nums){
            seq.push_back(num*num);
        }
        sort(seq.begin(),seq.end());
        int start=0,end=n-1;
        int flag=0;
        while(start<=end){
            if(flag==0){
                int num=seq[end];
                ans+=num;
                end--;
                flag=1;
            }
            else if(flag==1){
                int num=seq[start];
                ans-=num;
                start++;
                flag=0;
            }
        }
        return ans;
    }
};