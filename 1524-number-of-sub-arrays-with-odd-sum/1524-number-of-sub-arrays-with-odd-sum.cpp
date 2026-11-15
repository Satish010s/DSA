class Solution {
public:

    int numOfSubarrays(vector<int>& arr) {
        int n =arr.size();
        int MOD=1e9+7;
        long long  evenCount=1;
        long long  oddCount=0;
        long long  currSum=0;
        long long  total=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            if(currSum%2==1){
                total +=evenCount;
                oddCount++;
            }
            else{
                total+=oddCount;
                evenCount++;
            }
        }
        return total%MOD;
    }
};