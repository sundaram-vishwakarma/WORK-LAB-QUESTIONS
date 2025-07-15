class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freqMap;

        // Count frequencies
        for (int num : arr) {
            freqMap[num]++;
        }

        // Max heap (priority queue) for frequencies
        priority_queue<int> maxHeap;
        for (const auto& entry : freqMap) {
            maxHeap.push(entry.second);
        }

        int removed = 0;
        int count = 0;
        int half = arr.size() / 2;

        // Remove elements with highest frequency first
        while (removed < half) {
            removed += maxHeap.top();
            maxHeap.pop();
            count++;
        }

        return count;
    }
};
