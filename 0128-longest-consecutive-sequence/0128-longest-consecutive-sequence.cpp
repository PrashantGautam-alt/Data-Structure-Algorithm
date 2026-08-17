class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        // Put all numbers into the set
        for (int num : nums) {
            set.insert(num);
        }

        int ans = 0;

        // Try every number as a possible starting point
        for (auto it : set) {

            // If it-1 doesn't exist, this is the start
            // of a consecutive sequence
            if (set.find(it - 1) == set.end()) {

                int length = 1;
                int current = it;

                // Keep going while the next number exists
                while (set.find(current + 1) != set.end()) {
                    current++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};