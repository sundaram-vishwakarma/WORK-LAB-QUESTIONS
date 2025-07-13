class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefixProduct = nums[0];
        for (int i=1; i<n; i++) {       // O(n)
            ans[i] = prefixProduct;
            prefixProduct *= nums[i];
        }

        int suffixProduct = nums[n-1];
        for (int i=n-2; i>=0; i--) {    // O(n)
            ans[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return ans;
    }
};
