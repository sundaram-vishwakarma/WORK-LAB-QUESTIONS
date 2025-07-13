///// Brute Force Approach
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] > nums[k]) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};





///// Some Optimized Approach
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = n - 1; k >= j + 1; k--) {
                    if (nums[i] + nums[j] > nums[k]) {
                        count += k - j;
                        break;
                    }
                }
            }
        }

        return count;
    }
};






//// Most Optimized Approach
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int count = 0;
        for (int k = n - 1; k >= 2; k--) {
            int i = 0;
            int j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }

        return count;
    }
};
