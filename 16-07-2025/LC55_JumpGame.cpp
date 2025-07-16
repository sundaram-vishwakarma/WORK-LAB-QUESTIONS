class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(0, nums);
    }

private:
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (position >= nums.size() - 1) {
            return true; // Reached or exceeded last index
        }

        int furthestJump = min(position + nums[position], (int)nums.size() - 1);

        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }

        return false;
    }
};





//// GREEDY
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) {
                return false; // Current index is beyond the farthest reachable point
            }

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= nums.size() - 1) {
                return true; // Already can reach or exceed the last index
            }
        }

        return true; // Successfully traversed the array
    }
};
