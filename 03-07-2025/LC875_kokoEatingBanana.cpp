class Solution {
private:
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;
        
        for(int pile : piles) {
            actualHour += pile/givenHour;
            
            if(pile%givenHour != 0)
                actualHour++;
            
        }
        
        return actualHour <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = 0;
        for (int pile : piles) {
            high = max(high, pile);
        }

        while (low < high) {
            int mid = low + (high - low)/2;

            if (canEatAll(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
