class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // handle edge case where k <= 1

        int n = nums.size();
        int result = 0;
        int prod = 1;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            prod *= nums[j];

            while (i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }

            result += (j - i + 1);
        }

        return result;
    }
};

