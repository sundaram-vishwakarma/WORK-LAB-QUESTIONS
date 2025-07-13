#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int totalOne = 0;
        // Count total number of 1's in the string
        for (char ch : s) {
            if (ch == '1') totalOne++;
        }

        int left0 = 0;      // Count of 0's on the left side
        int right1 = totalOne; // Count of 1's on the right side
        if (s[0] == '0') {
            left0++;  // if first character is '0', increment left0
        } else {
            right1--;  // if first character is '1', decrement right1
        }

        int ans = left0 + right1;  // Initial score calculation

        // Iterate through the string from index 1 to length-2 to check other splits
        for (int i = 1; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                left0++;
            } else {
                right1--;
            }
            ans = max(ans, left0 + right1);  // Keep track of the maximum score
        }

        return ans;
    }
};

