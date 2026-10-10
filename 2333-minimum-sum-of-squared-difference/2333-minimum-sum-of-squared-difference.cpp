class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long  k=k1+k2;
        long long  ans=0;
        map<int,long long>numDiff;
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            numDiff[diff]++;
        }
       
        for(auto it = numDiff.rbegin(); it != numDiff.rend(); ++it){
            long long num=it->first;
            long long freq=it->second;
            if(k==0 ||num==0) break;
            if(k!=0 && freq<=k){
                numDiff[num-1]+=freq;
                numDiff[num]=0;
                k-=freq;
                
            }
            else if(k!=0 && freq>k){
                numDiff[num-1]+=k;
                numDiff[num]-=k;
                k=0;
                break;
            }
            
        }
        for(auto &it:numDiff){
                long long  num=it.first;
                long long  freq=it.second;
                ans+=(freq*num*num);
            }
    return ans;
    }

};