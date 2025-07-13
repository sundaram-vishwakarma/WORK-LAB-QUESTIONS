class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        int result = 0;

        // Count frequency of each number
        for (int num : nums) {
            map[num]++;
        }

        // Check for each number if num + 1 exists
        for (auto& pair : map) {
            int num = pair.first;
            if (map.count(num + 1)) {
                result = max(result, pair.second + map[num + 1]);
            }
        }

        return result;
    }
};
