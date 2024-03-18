class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();

    sort(begin(points), end(points));

    vector<int> prev = points[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
      int currentStartPoint = points[i][0];
      int currentEndPoint = points[i][1];

      int prevStartPoint = prev[0];
      int prevEndPoint = prev[1];

      if (currentStartPoint > prevEndPoint) { // No overlap, need a new arrow
        count++;
        prev = points[i];
      } else {
        // Overlap, update prev to maintain the maximum contiguous range
        prev[1] = min(prevEndPoint, currentEndPoint);
      }
    }

    return count;
  }
};