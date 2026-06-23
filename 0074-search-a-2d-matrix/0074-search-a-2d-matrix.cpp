class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int low = 0, high = n*m - 1;
        
        while(low <= high){
            int guess = low + (high-low)/2;
            int row_idx = guess/m;
            int col_idx = guess%m;

            if(matrix[row_idx][col_idx] == target) return true;

            if(matrix[row_idx][col_idx] < target) low = guess+1;
            else high = guess-1;
        }
        return false;
    }
};