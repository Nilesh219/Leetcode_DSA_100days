class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0]; // Start fast from the second element

    slow = nums[slow];
    fast = nums[nums[fast]];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = nums[0];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return fast;
  }
};