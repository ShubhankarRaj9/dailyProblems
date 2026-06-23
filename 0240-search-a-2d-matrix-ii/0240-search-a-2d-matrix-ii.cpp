// start from any anti-diagonal corner 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = n-1;
        int col = 0;

        while(row >= 0 && col <=m-1){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target) col++;
            else row--;
        }
        return false;
    }
};
