class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> window;
        int i =0;
        for(int j=0; j<n; j++){
            if(window.count(nums[j])){
                return true;
            }
            window.insert(nums[j]);
            if (j - i >= k) {
                window.erase(nums[i]);
                i++;
            }
        }
        return false;
        
    }
};