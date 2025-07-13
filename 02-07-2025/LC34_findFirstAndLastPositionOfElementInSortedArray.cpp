class Solution {
public:
    int BS(vector<int>& nums, int target, bool isFirst){
        int ans = -1;
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                ans = mid;
                if(isFirst){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int first = BS(nums, target, true);
        int last = BS(nums, target, false);
        ans[0] = first;
        ans[1] = last;
        return ans;
    }
};
