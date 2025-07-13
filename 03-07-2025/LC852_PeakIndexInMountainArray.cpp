class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /* initialize start */
        int start = 0;
        /* initialize end */
        int end = arr.size() - 1;

        /* calculate mid */
        int mid = start + (end - start)/2;

        /* loop run till start < end */
        while (start < end) {
            /* if arr[mid] < arr[mid+1] that means highest element in the right side */
            if (arr[mid] < arr[mid+1]) {
                start = mid + 1;
            } else {        /* else hoghest element in the left side */
                end = mid;
            }

            /* re-calculate mid */
            mid = start + (end - start)/2;
        }

        /* return start,
            for example: start = 2, end = 3;
            at the last mid calculate as mid = 2 + (3-2)/2 ==> 2
        
         */
        return mid;
    }
};
