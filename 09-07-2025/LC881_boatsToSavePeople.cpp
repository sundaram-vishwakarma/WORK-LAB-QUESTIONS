class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the people array
        sort(people.begin(), people.end());

        int i = 0;  // Pointer to the lightest person
        int j = people.size() - 1;  // Pointer to the heaviest person
        int boat = 0;  // Number of boats

        // Greedily try to pair the lightest and heaviest person
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;  // Lightest person paired with the heaviest
                j--;  // Decrease the index of the heaviest person
            } else {
                j--;  // Heaviest person goes alone
            }
            boat++;  // One more boat is used
        }

        return boat;
    }
};
