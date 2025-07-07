class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;
        int right = 0;
        
        Set<Character> seen = new HashSet<>();
        
        while (right < n) {
            if (!seen.contains(s.charAt(right))) {
                seen.add(s.charAt(right));
                right++;
                maxLength = Math.max(maxLength, right - left);
            } else {
                seen.remove(s.charAt(left));
                left++;
            }
        }
        return maxLength;
    }
}









// //// cpp
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         int maxLength = 0;
//         int left = 0, right = 0;
//         unordered_set<char> seen;

//         while (right < n) {
//             if (seen.find(s[right]) == seen.end()) {
//                 seen.insert(s[right]);
//                 right++;
//                 maxLength = max(maxLength, right - left);
//             } else {
//                 seen.erase(s[left]);
//                 left++;
//             }
//         }
//         return maxLength;
//     }
// };
