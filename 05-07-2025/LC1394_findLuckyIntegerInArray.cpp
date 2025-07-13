class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxEle = 1;

        // Find the maximum element in the array
        for (int a : arr) {
            maxEle = max(maxEle, a);
        }

        // Create a frequency array to count occurrences of each element
        vector<int> freq(maxEle + 1, 0);

        // Count the frequency of each element in the input array
        for (int a : arr) {
            freq[a]++;
        }

        // Check from maxEle down to 1 to find the lucky number
        for (int i = maxEle; i >= 1; i--) {
            if (i == freq[i]) {
                return i;
            }
        }

        // If no lucky number is found, return -1
        return -1;
    }
};
