class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
            int m = matrix.size();
            int n = matrix[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
            int maxArea = 0;

            // Fill the dp array with the height of consecutive 1s above (inclusive) each cell
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = (i == 0) ? 1 : dp[i - 1][j] + 1;
                    }
                }
            }

            // For each cell, calculate the area of the largest rectangle that can be formed with the cell as the           bottom-right corner
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] > 0) {
                        int minWidth = dp[i][j];
                        for (int k = j; k >= 0; --k) {
                            minWidth = min(minWidth, dp[i][k]);
                            maxArea = max(maxArea, minWidth * (j - k + 1));
                        }
                    }
                }
            }

            return maxArea;
    }
};