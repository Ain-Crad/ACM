class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, int> mp;
        vector<int> vec;
        for(int i = 0; i < len; i++){
            int rem = target - nums[i];
            if(mp.find(rem) == mp.end()) mp[nums[i]] = i;
            else{
                vec.push_back(mp[rem]);
                vec.push_back(i);
                return vec;
            }
        }
    }
};
