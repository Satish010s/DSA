class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        unordered_map<int, int> eleIdx;

        for (int i = 0; i < n; i++) {
            eleIdx[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            while (nums[i] != i) {
                int j = eleIdx[i];

                k &= nums[i] & nums[j];

                swap(nums[i], nums[j]);

                eleIdx[nums[i]] = i;
                eleIdx[nums[j]] = j;
            }
        }

        return max(k, 0);
    }
};