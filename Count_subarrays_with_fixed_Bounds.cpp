class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        
        long long ans = 0;
        int minp = -1;
        int maxp = -1;
        int culprit = -1;
        
        for(int i = 0; i < n; i++){

        
            if(nums[i] > maxK || nums[i] < minK)
                culprit = i;
            
            if(nums[i] == minK)
                minp = i;
            
            if(nums[i] == maxK)
                maxp = i;
            
            long long smaller = min(minp, maxp);
            
            lng long temp = smaller - culprit;
            
            ans += (temp<=0)? 0: temp;
        }
        return ans;
        
    }
};