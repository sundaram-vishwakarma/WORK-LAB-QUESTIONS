class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Print initial nums1 state (for debugging)
        for (int x : nums1) cout << x << " ";
        cout << endl;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }

            // Print after each merge step (for debugging)
            for (int x : nums1) cout << x << " ";
            cout << endl;
        }

        // If there are remaining elements in nums2, move them into nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];

            // Print after each merge step (for debugging)
            for (int x : nums1) cout << x << " ";
            cout << endl;
        }
    }
};
