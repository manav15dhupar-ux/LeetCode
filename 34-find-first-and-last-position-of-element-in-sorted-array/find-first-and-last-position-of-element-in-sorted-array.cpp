#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        
        // 1. Find the starting position
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // Prevents overflow error
            
            if (nums[mid] == target) {
                start = mid;       // Remember this index
                right = mid - 1;   // Keep looking LEFT to find an earlier one
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // 2. Find the ending position
        left = 0;
        right = nums.size() - 1; // Reset pointers for the second search
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                end = mid;         // Remember this index
                left = mid + 1;    // Keep looking RIGHT to find a later one
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return {start, end};
    }
};
