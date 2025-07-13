class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxVal = 0;  // Tracks the maximum value seen so far
        int chunks = 0;  // Number of chunks
        
        for (int i = 0; i < arr.size(); i++) {
            maxVal = max(maxVal, arr[i]);  // Update the maximum value
            
            // If the maximum value is equal to the current index, we can make a chunk
            if (maxVal == i) {
                chunks++;
            }
        }
        
        return chunks;
    }
};
