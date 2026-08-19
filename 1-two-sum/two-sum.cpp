class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
        unordered_map<int, int> mp;

        int n = arr.size();

        for (int i = 0; i < n; i++) {

            int need = target - arr[i];

            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            mp[arr[i]] = i;
        }

        return {};
    }
};