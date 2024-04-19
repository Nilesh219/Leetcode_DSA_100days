class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int islandCount = 0;

    // Create a visited grid to keep track of explored cells
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          dfs(grid, visited, i, j);
          islandCount++;
        }
      }
    }

    return islandCount;
  }

private:
  void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    // Mark current cell as visited
    visited[row][col] = true;

    // Explore all four adjacent cells
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int dir = 0; dir < 4; ++dir) {
      int newRow = row + directions[dir][0];
      int newCol = col + directions[dir][1];

      // Check if new cell is within grid boundaries, unvisited, and land
      if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && !visited[newRow][newCol] && grid[newRow][newCol] == '1') {
        dfs(grid, visited, newRow, newCol);
      }
    }
  }
};