class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> res;

        // Sort by item value (first element in each subarray)
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());

        int m = items1.size();
        int n = items2.size();

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (items1[i][0] == items2[j][0]) {
                // Merge values if item values match
                res.push_back({items1[i][0], items1[i][1] + items2[j][1]});
                i++;
                j++;
            } else if (items1[i][0] < items2[j][0]) {
                // Add from items1 if its value is smaller
                res.push_back({items1[i][0], items1[i][1]});
                i++;
            } else {
                // Add from items2 if its value is smaller
                res.push_back({items2[j][0], items2[j][1]});
                j++;
            }
        }

        // Add remaining elements
        while (i < m) {
            res.push_back({items1[i][0], items1[i][1]});
            i++;
        }

        while (j < n) {
            res.push_back({items2[j][0], items2[j][1]});
            j++;
        }

        return res;
    }
};
