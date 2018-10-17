class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int d1, d2;
        vector<int> vec;
        for(int i = 0; i < len; i++){
            for(int  j = i + 1; j < len; j++){
                if(nums[i] + nums[j] == target){
                    d1 = i;
                    d2 = j;
                    break;
                }
            }
        }
        vec.push_back(d1);
        vec.push_back(d2);
        return vec;
    }
};
