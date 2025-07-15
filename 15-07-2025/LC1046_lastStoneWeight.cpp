class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Create a max heap (priority_queue is max-heap by default in C++)
        priority_queue<int> maxHeap;

        // Push all stones into the max heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        // Process until there is at most one stone left
        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); maxHeap.pop(); // heaviest
            int x = maxHeap.top(); maxHeap.pop(); // second heaviest

            if (y != x) {
                maxHeap.push(y - x); // push the difference
            }
        }

        // Return the last stone or 0 if none remain
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
