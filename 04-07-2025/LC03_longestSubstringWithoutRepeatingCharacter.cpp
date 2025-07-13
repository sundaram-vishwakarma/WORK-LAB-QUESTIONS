class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0, right = 0;
        unordered_set<char> seen;

        while (right < n) {
            if (seen.find(s[right]) == seen.end()) {
                seen.insert(s[right]);
                right++;
                maxLength = max(maxLength, right - left);
            } else {
                seen.erase(s[left]);
                left++;
            }
        }
        return maxLength;
    }
};
