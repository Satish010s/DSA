class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
      int n=nums.size();
      vector<pair<int,int>>sorted;
      for(int i=0;i<n;i++){
        sorted.push_back({nums[i],i});
      }
      sort(sorted.begin(), sorted.end());
      vector<int> ans(n);
      int i=0;
          while (i < n) {
            int j = i + 1;
            while (j < n && sorted[j].first - sorted[j-1].first <= limit) {
                j++;
            }
            
            // Extract indices for the current group
            vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(sorted[k].second);
            }
            
            // 3. Sort the indices
            sort(indices.begin(), indices.end());
            
            // Assign sorted values to sorted indices
            for (int k = 0; k < indices.size(); ++k) {
                ans[indices[k]] = sorted[i + k].first;
            }
            
            i = j; // Advance pointer to next group
          }
          return ans;
    }
};