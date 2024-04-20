class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> groups;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    int x = i, y = j;
                    // Finding the bottom-right corner of the current farmland
                    while (x < m && land[x][j] == 1) {
                        y = j;
                        while (y < n && land[x][y] == 1) ++y;
                        ++x;
                    }
                    --x; --y; // Adjusting to the actual bottom-right corner
                    groups.push_back({i, j, x, y});
                    
                    // Marking this farmland as visited
                    for (int r = i; r <= x; ++r) {
                        for (int c = j; c <= y; ++c) {
                            land[r][c] = 0;
                        }
                    }
                }
            }
        }
        
        return groups;
    }
};