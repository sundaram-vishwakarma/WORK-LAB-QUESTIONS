class Solution {
public:
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    // Helper function for backtracking
    void possibality(const string& digits, int from, string res) {
        if (from >= digits.length()) {
            ans.push_back(res);
            return;
        }

        int digit = digits[from] - '0';  // Convert character to corresponding digit
        for (int i = 0; i < keypad[digit].length(); i++) {
            res.push_back(keypad[digit][i]);  // Add the character to the result string
            possibality(digits, from + 1, res);  // Recurse with the next digit
            res.pop_back();  // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        ans.clear();  // Clear previous results
        if (digits.empty()) {
            return ans;  // Return empty result if input is empty
        }

        possibality(digits, 0, "");  // Start the recursive process from the first digit
        return ans;
    }
};

