class Solution {
public:
    int findElements(vector<vector<int>>& matrix, int val) {
        int n = matrix.size();
        int cnt = 0;
        int row = n - 1, col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= val) {
                cnt += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n - 1][m - 1];

        int res = -1;

        while (low <= high) {
            int guess = low + (high - low) / 2;
            int val = findElements(matrix, guess);

            if (val < k) {
                low = guess + 1;
            } else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};