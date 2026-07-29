class Solution {
public:
    void fun(vector<int> & a, int n, int idx, int currSum, int targetVal, vector<int>& combination, vector<vector<int>>& res){
        if(idx == n) {
            if(currSum == targetVal)
                res.push_back(combination);
            return;
        }
        fun(a,n,idx+1,currSum,targetVal,combination,res);
        if(a[idx]+currSum <= targetVal){
            combination.push_back(a[idx]);
            currSum += a[idx];
            fun(a,n,idx,currSum,targetVal,combination,res);
            combination.pop_back();
            currSum -= a[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int idx = 0;
        int n = candidates.size();
        int sum = 0;
        vector<int> values;
        vector<vector<int>> results;
        fun(candidates, n, idx, sum, target, values, results);
        return results;
    }
};