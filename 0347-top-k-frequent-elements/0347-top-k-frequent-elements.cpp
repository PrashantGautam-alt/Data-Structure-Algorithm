class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }

        // Store {number, frequency}
        vector<pair<int, int>> arr;

        for(auto &[num, count]: mp){
            arr.push_back({num, count});
        }

        sort(arr.begin(), arr.end(), [](auto& a, auto& b){
            return a.second>b.second;
        });

        vector<int> ans;

        for(int i=0; i<k; i++){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};