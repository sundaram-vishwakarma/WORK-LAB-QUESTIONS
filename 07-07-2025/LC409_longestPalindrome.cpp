class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freqMap;

        // Count frequency of each character
        for (char c : s) {
            freqMap[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto& entry : freqMap) {
            int count = entry.second;
            length += (count / 2) * 2;
            if (count % 2 == 1) {
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length += 1;
        }

        return length;
    }
};
