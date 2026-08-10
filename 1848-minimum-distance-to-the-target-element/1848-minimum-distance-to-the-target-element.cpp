class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minAns = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                minAns = min(minAns,abs(start-i));
            }
        }
        return minAns;
    }
};