class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count task frequencies
        vector<int> mp(26, 0);
        for (char &ch : tasks) {
            mp[ch - 'A']++;
        }

        // Find the maximum task frequency
        int max_freq = *max_element(mp.begin(), mp.end());

        // Count the number of tasks with the maximum frequency
        int tasks_with_max_freq = 0;
        for (int freq : mp) {
            if (freq == max_freq) {
                tasks_with_max_freq++;
            }
        }

        // Calculate the minimum time based on cooling period and max frequency
        int min_time = tasks.size();  // Base case: all tasks have the same frequency
        if (n > 0) {
            // Consider the cooling period
            min_time = max(min_time, (max_freq - 1) * (n + 1) + tasks_with_max_freq);
        }

        return min_time;
    }
};
