class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLen = -1;
        vector<int> firstIndex(26, -1);  // For 26 lowercase English letters

        for (int i = 0; i < s.length(); ++i) {
            int chIndex = s[i] - 'a';
            if (firstIndex[chIndex] == -1) {
                firstIndex[chIndex] = i;  // Store first occurrence
            } else {
                int length = i - firstIndex[chIndex] - 1;
                maxLen = max(maxLen, length);
            }
        }

        return maxLen;
    }
};

