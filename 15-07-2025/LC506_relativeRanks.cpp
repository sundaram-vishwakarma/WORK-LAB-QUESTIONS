///// M-1
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int, int> indexMap;
        priority_queue<int> maxHeap;

        // Store the index of each score and add scores to maxHeap
        for (int i = 0; i < n; ++i) {
            indexMap[score[i]] = i;
            maxHeap.push(score[i]);
        }

        vector<string> ans(n);

        int rank = 1;
        while (!maxHeap.empty()) {
            int idx = indexMap[maxHeap.top()];
            if (rank == 1) {
                ans[idx] = "Gold Medal";
            } else if (rank == 2) {
                ans[idx] = "Silver Medal";
            } else if (rank == 3) {
                ans[idx] = "Bronze Medal";
            } else {
                ans[idx] = to_string(rank);
            }
            maxHeap.pop();
            ++rank;
        }

        return ans;
    }
};








////// M-2
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        // Max heap storing pair<score, index>
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({score[i], i});
        }

        vector<string> ans(n);
        int rank = 1;

        while (!pq.empty()) {
            int idx = pq.top().second;
            if (rank == 1) {
                ans[idx] = "Gold Medal";
            } else if (rank == 2) {
                ans[idx] = "Silver Medal";
            } else if (rank == 3) {
                ans[idx] = "Bronze Medal";
            } else {
                ans[idx] = to_string(rank);
            }
            pq.pop();
            ++rank;
        }

        return ans;
    }
};
