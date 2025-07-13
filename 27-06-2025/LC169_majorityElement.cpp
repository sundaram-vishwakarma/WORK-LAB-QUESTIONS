///////// Optimal
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        
        // Phase 1: Find the candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        // Phase 2: The candidate is guaranteed to be the majority element 
        // because it's guaranteed to exist.
        return candidate;
    }
};
