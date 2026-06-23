class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m=matrix[0].size();
        int low_row = 0, high_row = n-1;
        int targetted_row = -1;
        if(target < matrix[0][0] || target > matrix[n-1][m-1]) return false;
        while(low_row <= high_row){
            int guess = low_row + (high_row - high_row) /2;
            if(matrix[guess][0] <= target){
                targetted_row = guess;
                low_row = guess + 1;
            }
            else{
                high_row = guess - 1;
            }
        }

        int low = 0, high = m-1;
        
        while(low <= high){
            int guess = low + (high-low)/2;
            if(matrix[targetted_row][guess] == target) return true;
            if(matrix[targetted_row][guess] < target)  {
                low = guess+1;
            }
            else {
                high = guess-1;
            }
        }
     return false;
    }
};