class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len1==0 || len2==0) {
            return ans;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int idx1 = 0;
        int idx2 = 0;

        while (idx1<len1 && idx2<len2) {
            if (nums1[idx1] == nums2[idx2]) {
                ans.push_back(nums1[idx1]);
                while (idx1 < len1 && nums1[idx1] == ans.back()) {
                    idx1++;
                }
                while (idx2 < len2 && nums2[idx2] == ans.back()) {
                    idx2++;
                }
            } else if (nums1[idx1] < nums2[idx2]) {
                idx1++;
            } else {
                idx2++;
            }
        }

        return ans;
    }
};
