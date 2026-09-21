class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int current = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            current += nums[i];
            ans = max(ans, current);
            current = max(current, 0);
        }
        return ans;
    }
};