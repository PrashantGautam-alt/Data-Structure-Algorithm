class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++){
            int candidate = target - nums[i];
            if(mp.find(candidate)!=mp.end()){
                return {mp[candidate],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};